#pragma once
#include "Eigen/Core"

class Camera
{
public:
	Camera(const Eigen::Matrix4f& view,const Eigen::Matrix4f projection)
		:m_View(view),m_Projection(projection){}
	Camera(){}
	~Camera(){}
	Camera& operator=(const Camera& ori)
	{
		m_View = ori.m_View;
		m_Projection = ori.m_Projection;
		return *this;
	}
	inline const Eigen::Matrix4f& GetView()const { return m_View; }
	inline const Eigen::Matrix4f& GetProjection()const { return m_Projection; }
private:
	Eigen::Matrix4f m_View;
	Eigen::Matrix4f m_Projection;
};