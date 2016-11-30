#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	srand(time(NULL));
	mundo.Iniciar(ofVec2f(0, 0), "mapa/terreno.jpg");						// Inicia o mundo
	player.Iniciar(ofVec2f(480, 1390), mundo.GetEnderecoPosicao());			// Inicia o player
	controlador.Iniciar(mundo.GetEnderecoPosicao(), &player);				// Inicia a rota dos creeps destemidos
	mundo.SetPosicao(ofVec2f( 0, -1000));

}


//--------------------------------------------------------------
void ofApp::update(){

	/* Controlador da camera */
	mundo.ControladorCam(player.GetPosicao());

	/* Atualiza a posicao do player */
	player.Atualizar(mundo.GetPosicao(), controlador.GetPosicaoCreep(player.GetCreepID()));
	player.Atacar();

	/* Atualiza a posizao dos creeps*/
	controlador.Atualizar();
}

//--------------------------------------------------------------
void ofApp::draw(){
	mundo.Draw(mundo.GetPosicao());				//Desenha o mundo
	player.Draw(mundo.GetPosicao());			//Desenha o player
	controlador.Draw();							//Desenha os creeps
	if (controlador.GetDesenharRota()) {
		controlador.DrawRota();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == ' ')
		mundo.ToggleCam();

	if ((key == 'i') || (key == 'I'))
		controlador.SetDesenharRota(true);

	if (key == '+')
		controlador.AumentarVelocidadeRespaw();

	if (key == '-')
		controlador.DiminuirVelocidadeRespaw();
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if ((key == 'i') || (key == 'I'))
		controlador.SetDesenharRota(false);
	if ((key == 'q') || (key == 'Q'))
		player.m_condemnAtaque.SetAtivar(true);

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if (button == OF_MOUSE_BUTTON_RIGHT) {
		player.SetAtaqueEsseC§reep(controlador.MouseClicouEm());
		player.SetProxPosicao(ofVec2f(x, y) - mundo.GetPosicao());
		

	}

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
