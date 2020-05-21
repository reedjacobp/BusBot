#ifndef _ROS_ros_waypoint_generator_Waypoint_h
#define _ROS_ros_waypoint_generator_Waypoint_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Pose.h"

namespace ros_waypoint_generator
{

  class Waypoint : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int32_t _number_type;
      _number_type number;
      typedef geometry_msgs::Pose _pose_type;
      _pose_type pose;
      typedef int32_t _is_search_area_type;
      _is_search_area_type is_search_area;
      typedef float _reach_tolerance_type;
      _reach_tolerance_type reach_tolerance;

    Waypoint():
      header(),
      number(0),
      pose(),
      is_search_area(0),
      reach_tolerance(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_number;
      u_number.real = this->number;
      *(outbuffer + offset + 0) = (u_number.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_number.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_number.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_number.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->number);
      offset += this->pose.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_is_search_area;
      u_is_search_area.real = this->is_search_area;
      *(outbuffer + offset + 0) = (u_is_search_area.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_is_search_area.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_is_search_area.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_is_search_area.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->is_search_area);
      offset += serializeAvrFloat64(outbuffer + offset, this->reach_tolerance);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_number;
      u_number.base = 0;
      u_number.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_number.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_number.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_number.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->number = u_number.real;
      offset += sizeof(this->number);
      offset += this->pose.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_is_search_area;
      u_is_search_area.base = 0;
      u_is_search_area.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_is_search_area.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_is_search_area.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_is_search_area.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->is_search_area = u_is_search_area.real;
      offset += sizeof(this->is_search_area);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->reach_tolerance));
     return offset;
    }

    const char * getType(){ return "ros_waypoint_generator/Waypoint"; };
    const char * getMD5(){ return "522a0978e774a47933c16d3e9d0fcf91"; };

  };

}
#endif