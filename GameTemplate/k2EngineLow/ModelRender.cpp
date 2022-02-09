#include "k2EngineLowPreCompile.h"
#include "ModelRender.h"

namespace nsK2EngineLow
{
	void ModelRender::Init
	(const char* filePath,
		AnimationClip* animationClips,
		int numAnimationClips,
		EnModelUpAxis enModelUpAxis,
		bool isShadowReciever)
	{
		InitSkeleton(filePath);
		InitAnimation(animationClips, numAnimationClips, enModelUpAxis);
		ModelInitData initData;
		initData.m_tkmFilePath = filePath;
		initData.m_fxFilePath = "Assets/shader/Model.fx";
		initData.m_vsEntryPointFunc = "VSMain";

		if (m_animationClips != nullptr)
		{
			initData.m_vsSkinEntryPointFunc = "VSSkinMain";
			initData.m_skeleton = &m_skeleton;
		}

		initData.m_modelUpAxis = enModelUpAxis;
		initData.m_colorBufferFormat[0] = DXGI_FORMAT_R32G32B32A32_FLOAT;

		m_model.Init(initData);

	}

	void ModelRender::InitSkeleton(const char* filePath)
	{
		std::string skeletonFilePath = filePath;
		int position = (int)skeletonFilePath.find(".tkm");
		skeletonFilePath.replace(position, 4, ".tks");
		m_skeleton.Init(skeletonFilePath.c_str());
	}

	void ModelRender::InitAnimation
	(AnimationClip* animationClips,
		int numAnimationClips,
		EnModelUpAxis enModelUpAxis)
	{
		m_animationClips = animationClips;
		m_numAnimationClips = numAnimationClips;
		if (m_animationClips != nullptr)
		{
			m_animation.Init
			(m_skeleton,
				m_animationClips,
				m_numAnimationClips);
		}
	}

	void ModelRender::Draw(RenderContext& rc)
	{
		m_model.Draw(rc);
	}

	void ModelRender::Update()
	{		
		m_model.UpdateWorldMatrix(m_position,m_rotation,m_scale); 
		if(m_skeleton.IsInited())
		m_skeleton.Update(m_model.GetWorldMatrix());
		m_animation.Progress(g_gameTime->GetFrameDeltaTime());
	}
}
