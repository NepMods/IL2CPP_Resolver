#pragma once

namespace Unity
{
	struct STransformFunctions
	{
		void* m_pGetPosition = nullptr;
		void* m_pGetLocalPosition = nullptr;
		void* m_pGetLocalRotation = nullptr;
		void* m_pGetLocalScale = nullptr;
		void* m_pSetPosition = nullptr;
		void* m_pSetLocalPosition = nullptr;
		void* m_pSetLocalRotation = nullptr;
		void* m_pSetLocalScale = nullptr;
	};
	extern STransformFunctions TransformFunctions;

	class CTransform : public IL2CPP::CClass
	{
	public:
		Vector3 GetPosition()
		{
			Vector3 vRet;
			reinterpret_cast<void(UNITY_CALLING_CONVENTION)(void*, Vector3&)>(TransformFunctions.m_pGetPosition)(this, vRet);
			return vRet;
		}

		Vector3 GetLocalPosition()
		{
			Vector3 vRet;
			reinterpret_cast<void(UNITY_CALLING_CONVENTION)(void*, Vector3&)>(TransformFunctions.m_pGetLocalPosition)(this, vRet);
			return vRet;
		}

		Vector3 GetLocalRotation()
		{
			Vector3 vRet;
			reinterpret_cast<void(UNITY_CALLING_CONVENTION)(void*, Vector3&)>(TransformFunctions.m_pGetLocalRotation)(this, vRet);
			return vRet;
		}

		Vector3 GetLocalScale()
		{
			Vector3 vRet;
			reinterpret_cast<void(UNITY_CALLING_CONVENTION)(void*, Vector3&)>(TransformFunctions.m_pGetLocalScale)(this, vRet);
			return vRet;
		}

		void SetPosition(Vector3 m_vVector)
		{
			reinterpret_cast<void(UNITY_CALLING_CONVENTION)(void*, Vector3)>(TransformFunctions.m_pSetPosition)(this, m_vVector);
		}

		void SetLocalPosition(Vector3 m_vVector)
		{
			reinterpret_cast<void(UNITY_CALLING_CONVENTION)(void*, Vector3)>(TransformFunctions.m_pSetLocalPosition)(this, m_vVector);
		}

		void SetLocalRotation(Vector3 m_vVector)
		{
			reinterpret_cast<void(UNITY_CALLING_CONVENTION)(void*, Vector3)>(TransformFunctions.m_pSetLocalRotation)(this, m_vVector);
		}

		void SetLocalScale(Vector3 m_vVector)
		{
			reinterpret_cast<void(UNITY_CALLING_CONVENTION)(void*, Vector3)>(TransformFunctions.m_pSetLocalScale)(this, m_vVector);
		}
	};

	namespace Transform
	{
		void Initialize();
	}
}