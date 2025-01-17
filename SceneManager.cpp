#include "SceneManager.h"
#include <cassert>

#include "SceneTitle.h"



SceneManager::SceneManager()
{
	//m_kind = kSceneKindTitle;
	m_pScene = nullptr;
}
SceneManager::~SceneManager()
{

}

void SceneManager::init(SceneKind kind)
{
	
	m_pScene = new SceneTitle;
	m_pScene->init();

}

void SceneManager::end()
{
	assert(m_pScene);
	if (!m_pScene) return;

	m_pScene->end();
	delete m_pScene;
}

void SceneManager::update()
{
	assert(m_pScene);
	if (!m_pScene) return;

	SceneBase* pScene = m_pScene->update();		//nullでなければupdate処理を行う
	if (pScene != m_pScene)
	{
		//前のシーンの終了処理
		m_pScene->end();
		delete m_pScene;

		m_pScene = pScene;
		m_pScene -> init();
	}

}

void SceneManager::draw()
{
	assert(m_pScene);
	if (!m_pScene) return;

	m_pScene->draw();		//nullでなければupdate処理を行う
}