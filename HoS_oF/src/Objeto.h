#pragma once
#include "ofVec2f.h"

class Objeto {
	protected:
		ofVec2f m_posicao;

	public:
		virtual void Draw(ofVec2f mundo) = 0;
		void SetPosicao(ofVec2f posicao);
		ofVec2f GetPosicao();
};