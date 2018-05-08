#ifndef _SINGLETON_H_
#define _SINGLETON_H_

#define DECLARE_SINGLETON(ClassName)			\
public:											\
	static ClassName* GetInstance()				\
	{											\
		if (m_pInstance == nullptr)				\
			m_pInstance = new ClassName;		\
												\
		return m_pInstance;						\
	}											\
												\
	void DestroyInstance()						\
	{											\
		if (m_pInstance)						\
		{										\
			delete m_pInstance;					\
			m_pInstance = nullptr;				\
		}										\
	}											\
												\
private:										\
	static ClassName* m_pInstance;				\

#define IMPLEMENT_SINGLETON(ClassName)			\
ClassName* ClassName::m_pInstance = nullptr;

#endif // !_SINGLETON_H_
