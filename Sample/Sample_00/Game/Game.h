#pragma once

class Game : public IGameObject
{
public:
	
	bool Start() override;
	void Update() override;
	void Render(RenderContext& rc) override;
private:
	enum EnAnimationClips
	{
		enIdle,
		enWalk,
		enRun,
		enNum
	};
	Model m_model;
	ModelRender modelRender;
	ModelRender anotherRender;
	AnimationClip animationClips[enNum];
	int numAnimationClips;
	Vector3 position = { 0.0f,0.0f,-300.0f };
	Vector3 playerPosition[2] =
	{
		Vector3::Zero,
		{0.0f,0.0f,0.0f} };
	float cameraSpeed = 1.0f;
};

