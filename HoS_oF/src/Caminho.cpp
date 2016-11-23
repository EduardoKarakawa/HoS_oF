#include "Caminho.h"

void Caminho::Inicializar(ofVec2f mundo) {
	/*Iniciando as posicoes padroes dos pontos*/
	m_listaPontos[0] = ofVec2f(3200, 1555) + mundo;
	m_listaPontos[1] = ofVec2f(2550, 925) + mundo;
	m_listaPontos[2] = ofVec2f(1945, 850) + mundo;
	m_listaPontos[3] = ofVec2f(1330, 915) + mundo;
	m_listaPontos[4] = ofVec2f(680, 1555) + mundo;

	/*m_posNovoPonto sera usado para poder identificar qual ponto do caminho sera reajustado a posicao*/
	m_posNovoPonto = 0;
}




/*
	Mudar os pontos do caminho dos creeps
*/
void Caminho::NovoCaminho(ofVec2f novaPosicao, ofVec2f mundo){
	
	m_listaPontos[m_posNovoPonto] = novaPosicao + mundo;

}




/*
	Retorna as coordenadas de um ponto do caminho
*/
ofVec2f Caminho::PegarPosicaoDe(int indice) {
	if (indice > -1)
		return m_listaPontos[indice];
	else
		return ofVec2f(0, 0);
}




/*
	Muda os pontos do caminho
*/
void Caminho::SetCaminho(ofVec2f novaRota[5]) {
	for (int i = 0; i < 5; i++) {
		m_listaPontos[i] = novaRota[i];
	}
}




/*
	Retorna a distancia entre um ponto da lista e o ponto desejado
*/
float Caminho::GetDistancia(int indice, ofVec2f ponto){
	return m_listaPontos[indice].distance(ponto);
}
