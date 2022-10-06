#include "DxLib.h"
#include "SceneTest.h"
#include "SceneTitle.h"

void SceneTest::init()
{
	m_textPosX = 0;
	m_textVecX = 4;

	m_isEnd = false;
}

SceneBase* SceneTest::update()
{
	// 文字の移動
	m_textPosX += m_textVecX;
	if (m_textPosX < 0)
	{
		m_textPosX = 0;
		m_textVecX = 4;
	}
	if (m_textPosX > 300)
	{
		m_textPosX = 300;
		m_textVecX = -4;
	}

	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (padState & PAD_INPUT_3)
	{
		return (new SceneTitle);
	}
	return this;
}

void SceneTest::draw()
{
	DrawString(m_textPosX, 0, "テスト画面(・-・)", GetColor(255, 255, 255));
}