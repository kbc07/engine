#include "stdafx.h"
#include "Game.h"


bool Game::Start()
{
	animationClips[enIdle].Load("Assets/animData/idle.tka");
	animationClips[enIdle].SetLoopFlag(true);
	animationClips[enWalk].Load("Assets/animData/walk.tka");
	animationClips[enWalk].SetLoopFlag(true);
	animationClips[enRun].Load("Assets/animData/run.tka");
	animationClips[enRun].SetLoopFlag(true);

	modelRender.Init("Assets/modelData/unityChan.tkm", animationClips, enNum, enModelUpAxisY);
	anotherRender.Init("Assets/modelData/preset/bg/bg.tkm");
	modelRender.SetPosition(playerPosition[0]);
	anotherRender.SetPosition(playerPosition[1]);
	return true;
}
void Game::Update()
{
	if (g_pad[0]->IsPress(enButtonRight))
	{
		playerPosition[0].x += 1.0f;
		modelRender.PlayAnimation(enWalk);

	}
	else if (g_pad[0]->IsPress(enButtonUp))
	{
		playerPosition[0].z += 1.0f;
		modelRender.PlayAnimation(enRun);
	}
	else if (g_pad[0]->IsPress(enButtonLeft))
	{
		playerPosition[0].x -= 1.0f;
		modelRender.PlayAnimation(enWalk);
	}
	else if (g_pad[0]->IsPress(enButtonDown))
	{
		playerPosition[0].z -= 1.0f;
		modelRender.PlayAnimation(enRun);
	}
	else
	{
		modelRender.PlayAnimation(enIdle);
	}

	position = { playerPosition[0].x,playerPosition[0].y + 50.0f,playerPosition[0].z - 300.0f };
	g_camera3D->SetPosition(position);
	g_camera3D->SetTarget(playerPosition[0]);
	g_camera3D->Update();
	modelRender.SetPosition(playerPosition[0]);
	anotherRender.SetPosition(playerPosition[1]);
	modelRender.Update();
	anotherRender.Update();
}
void Game::Render(RenderContext& rc)
{
	//m_model.Draw(rc);
	modelRender.Draw(rc);
	anotherRender.Draw(rc);
}