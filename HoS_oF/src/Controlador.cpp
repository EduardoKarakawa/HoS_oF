#include "Controlador.h"

/*---------------------------------------------------------------------------------------------
	Inicia os parametros da class ControladorCreep
---------------------------------------------------------------------------------------------*/
void Controlador::Iniciar(ofVec2f* mundo, Jogador* player) {
	m_player = player;
	m_tempoRespaw = 4.f;
	m_contTempoRespaw = m_tempoRespaw;
	m_mundo = mundo;
	m_rota.Inicializar(*m_mundo);
	m_totalCreep = 1;
	m_listaCreeps = new Creep[m_totalCreep];

	for (int i = 0; i < m_totalCreep; i++)
		m_listaCreeps[i].Iniciar(&m_rota, rand() % 10000000);

	m_desenharRota = false;
}






/*---------------------------------------------------------------------------------------------
	Realiza uma verificacao de tempo para poder criar um novo creep e atualiza a posicao dos creeps vivos
---------------------------------------------------------------------------------------------*/
void Controlador::Atualizar() {
	/* Verifica se ja passou o tempo de necessario para spawnar um novo creep*/
	if (m_contTempoRespaw <= 0) {
		/* Inicia o ultimo creep da lista que foi criado durante a reorganizacao da lista*/
		m_listaCreeps = OrganizarListaCreep();
		m_contTempoRespaw = m_tempoRespaw;
	}

	
	m_contTempoRespaw -= ofGetLastFrameTime(); // Subtrai o tempo de respaw
	

	/* Percorre a lista de creeps atualizando as posicoes se ele estiver vivo */
	int tmp_cont = 0;
	for (int i = 0; i < m_totalCreep; i++){ //Aki sera contado o creeps que estao perto da enchantress para poder colocar eles envolta dela
		if (m_rota.GetDistancia(4, m_listaCreeps[i].GetPosicao()) <= 60.f) {
			tmp_cont++;
		}
	}
	for (int i = 0; i < m_totalCreep; i++) {
		if (m_listaCreeps[i].GetVivo()) {
			m_listaCreeps[i].Atualizar((360.f / (tmp_cont*1.f)) * i, m_player->GetPosicao());
		}
	}


	if (m_player->GetTiroAtingiu()) {
		for (int j = 0; j < m_totalCreep; j++) {
			if (m_listaCreeps[j].GetId() == m_player->GetCreepID()) {
				m_listaCreeps[j].LevarDano(m_player->GetDanoPadrao() + rand() % 10);
				m_player->SetTiroAtingiu(false);
			}
					
		}
	}


	m_listaCreeps = m_player->m_condemnAtaque.AplicarDano(m_player->GetPosicao(), m_listaCreeps, m_totalCreep);

	
}







/*---------------------------------------------------------------------------------------------
	Percorre a lista de creeps desenhando eles.
---------------------------------------------------------------------------------------------*/
void Controlador::Draw() {
	
	for (int i = 0; i < m_totalCreep; i++) {
		if(m_listaCreeps[i].GetVivo())
			m_listaCreeps[i].Draw(*m_mundo);
	}
}









/*---------------------------------------------------------------------------------------------
	Percorre a lista de creeps desenhando a rota.
---------------------------------------------------------------------------------------------*/
void Controlador::DrawRota(){
	ofPath rota;
	ofColor cor = ofColor(102, 244, 255);

	rota.setFilled(false);
	rota.setStrokeWidth(5);
	rota.setStrokeColor(cor);

	ofSetColor(cor);

	ofDrawCircle(m_rota.PegarPosicaoDe(0) + *m_mundo, 25);
	rota.moveTo(m_rota.PegarPosicaoDe(0) + *m_mundo);

	for (int i = 1; i < 5; i++) {
		ofDrawCircle(m_rota.PegarPosicaoDe(i) + *m_mundo, 25);
		rota.lineTo(m_rota.PegarPosicaoDe(i) + *m_mundo);
	}
	rota.draw();
	ofSetColor(255, 255, 255);
}





/*---------------------------------------------------------------------------------------------
	Recoorganiza a lista de creeps e acrescenta 1 no final para ser o proximo 
	creep que vai spawnar.
---------------------------------------------------------------------------------------------*/
Creep*  Controlador::OrganizarListaCreep() {
	Creep* tmp;
	int cont = 0;
	bool adicionarUm = false;
	std::cout << m_totalCreep;
	/* Verifica o total de creeps vivos*/
	for (int i = 0; i < m_totalCreep; i++) {

		if (m_listaCreeps[i].GetVivo()) {
			cont++;
			std::cout << "|"<< cont;
		}
		else if (!m_listaCreeps[i].GetVivo()) {
			m_listaCreeps[i].Iniciar(&m_rota, rand() % 10000000);
			adicionarUm = true;
			break;
		}

	}

	if (!adicionarUm) {

		m_totalCreep = cont + 1;
		cont = 0;
		tmp = new Creep[m_totalCreep];
		std::cout << "    " << m_totalCreep;
		/* Coloca na nova lista so os creeps que estao vivos*/
		for (int i = 0; i < m_totalCreep - 1; i++) {
			if (m_listaCreeps[i].GetVivo()) {
				tmp[cont] = m_listaCreeps[i];
				cont++;
			}
		}
		std::cout << std::endl;
		tmp[m_totalCreep - 1].Iniciar(&m_rota, rand() % 10000000);
		return tmp;
	}

	std::cout << std::endl;
	return m_listaCreeps;

	
}





/*---------------------------------------------------------------------------------------------
	Muda o valor da variavel desenharRota, usada para liberar a funcao que desenha a rota dos creeps.
---------------------------------------------------------------------------------------------*/
void Controlador::SetDesenharRota(bool mudar){
	m_desenharRota = mudar;
}







/*---------------------------------------------------------------------------------------------
	Retorna o valor da variavel desenharRota.
---------------------------------------------------------------------------------------------*/
bool Controlador::GetDesenharRota(){
	return m_desenharRota;
}



/*---------------------------------------------------------------------------------------------
	Verifica se o jogador cliclou em algum creep e retorna um ponteiro para ele,
	se nao retorna um nullptr
---------------------------------------------------------------------------------------------*/
int Controlador::MouseClicouEm(){
	ofVec2f tmp_mouse = ofVec2f(ofGetMouseX(), ofGetMouseY()) - *m_mundo;
	for (int i = 0; i < m_totalCreep; i++) {
		if (tmp_mouse.distance(m_listaCreeps[i].GetPosicao()) <= 25.f) {
			return m_listaCreeps[i].GetId();
		}
	}
	return NULL;
}




/*---------------------------------------------------------------------------------------------
	Aumenta a velocida de respaw dos creeps
---------------------------------------------------------------------------------------------*/
void Controlador::AumentarVelocidadeRespaw() {
	m_tempoRespaw += 0.1f;
}



/*---------------------------------------------------------------------------------------------
	Diminui a velocida de respaw dos creeps
---------------------------------------------------------------------------------------------*/
void Controlador::DiminuirVelocidadeRespaw(){
	m_tempoRespaw -= 0.1f;
}

ofVec2f Controlador::GetPosicaoCreep(int id){
	for (int i = 0; i < m_totalCreep; i++)	{
		if (m_listaCreeps[i].GetId() == id)
			return m_listaCreeps[i].GetPosicao();
	}

	return ofVec2f(0, 0);
}


