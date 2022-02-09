#pragma once
#include "k2EngineLowPreCompile.h"

namespace nsK2EngineLow
{
	class ModelRender 
	{
	public:
		ModelRender() {};
		~ModelRender() {};
		void Init
		(const char* filePath,
			AnimationClip* animationClips = nullptr,
			int numAnimationClips = 0,
			EnModelUpAxis enModelUpAxis = enModelUpAxisZ,
			bool isShadowReciever = true);
		void PlayAnimation(int animNo, float interpolateTime = 0.0f)
		{
			m_animation.Play(animNo, interpolateTime);
		};
		void SetAnimationSpeed(const float animationSpeed)
		{
			m_animationSpeed = animationSpeed;
		};
		void SetPosition(const Vector3& position)
		{
			m_position = position;
		}
		void SetRotation(const Quaternion& rotation)
		{
			m_rotation = rotation;
		}
		void SetScale(const Vector3& scale)
		{
			m_scale = scale;
		}
		void Update();
		void Draw(RenderContext& rc);

	private:
		void InitSkeleton(const char* filePath);
		void InitAnimation(AnimationClip* animationClips, int numAnimationClips, EnModelUpAxis enModelUpAxis);

	private:
		AnimationClip* m_animationClips = nullptr;
		int m_numAnimationClips = 0;
		Vector3 m_position = Vector3::Zero;
		Quaternion m_rotation = Quaternion::Identity;
		Vector3 m_scale = Vector3::One;
		Animation m_animation;
		Skeleton m_skeleton;
		float m_animationSpeed = 1.0f;
		Model m_model;
	};
}

