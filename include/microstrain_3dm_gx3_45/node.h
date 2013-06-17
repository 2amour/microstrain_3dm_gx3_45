
#include "geometry_msgs/PoseStamped.h"
#include "sensor_msgs/Imu.h"
#include "std_srvs/Empty.h"
#include "tf/transform_datatypes.h"
#include <tf/LinearMath/Matrix3x3.h>

#ifndef NODE_H_
#define NODE_H_

namespace microstrain_3dm_gx3_45 {

class imuNode {

	public:

		imuNode();
		~imuNode();

		bool init();
		void spin();

		void printErrMsgs(std::string prefix);

	protected:

		IMU imu_;

		ros::NodeHandle nh_;
		ros::NodeHandle nh_priv_;

		std::string port_;
		int baud_rate_;
		int declination_;

		bool started_;
		bool inited_;

		std::string frame_id_;

		ros::Publisher imu_data_pub_;

		ros::Publisher imu_pose_pub_;

		bool start();
		bool stop();

		double linear_acceleration_stdev_;
		double orientation_stdev_;
		double angular_velocity_stdev_;

		float rate_;

		ros::ServiceServer service_reset_;

		bool srvResetKF(std_srvs::Empty::Request &req, std_srvs::Empty::Response &res);

		bool publish_pose_;
		bool publish_imu_;

	private:

};



} // ns


#endif /* NODE_H_ */
