#include <ros/ros.h>

#include <geometry_msgs/Twist.h>
#include <turtlesim/Pose.h>
using namespace std;


int main(int argc, char **argv)
{
	const double FORWARD_SPEED_MPS = 2.5;
	const double GIRO = 2.5;
	ros::init(argc,argv,"move_turtle");
	ros::NodeHandle nh;
	//ROS_INFO_STREAM("ejemplo_pub_node initialized");																																							
	//ROS_INFO_STREAM(ros::this_node::getName());

	ros::Publisher pub = nh.advertise<geometry_msgs::Twist> ("turtle1/cmd_vel", 10);

	//ros::Subscriber sub = nh.Subscribe("turtle1/pose",10, poseCallback);

	geometry_msgs::Twist msg;
	
	msg.angular.x=2;
	msg.angular.y=4;
	msg.angular.z=2;
	int ms;
	//ros::RATE rate(10);
	ROS_INFO("COMINO");
	while (ros::ok())
	{
		cout << "¿Movimiento?" << endl;
		cin >> ms;
		switch(ms){
			case 2:
				msg.linear.x = FORWARD_SPEED_MPS;
				msg.angular.z = GIRO;
			break;
			case 4:
				msg.angular.z = 0;
				msg.linear.x = -FORWARD_SPEED_MPS;
			break;
			case 6:
				msg.angular.z = 0;
				msg.linear.x = FORWARD_SPEED_MPS;
			break;
			case 8:
				msg.angular.z = -GIRO;
				msg.linear.x = FORWARD_SPEED_MPS;
			break;
		}
		pub.publish(msg);
		ros::spinOnce();
		//rate.sleep();
	}

    return 1;
}
