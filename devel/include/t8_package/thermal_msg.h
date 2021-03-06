// Generated by gencpp from file t8_package/thermal_msg.msg
// DO NOT EDIT!


#ifndef T8_PACKAGE_MESSAGE_THERMAL_MSG_H
#define T8_PACKAGE_MESSAGE_THERMAL_MSG_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace t8_package
{
template <class ContainerAllocator>
struct thermal_msg_
{
  typedef thermal_msg_<ContainerAllocator> Type;

  thermal_msg_()
    : header()
    , id(0)
    , temp(0)  {
    }
  thermal_msg_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , id(0)
    , temp(0)  {
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef int8_t _id_type;
  _id_type id;

   typedef int8_t _temp_type;
  _temp_type temp;




  typedef boost::shared_ptr< ::t8_package::thermal_msg_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::t8_package::thermal_msg_<ContainerAllocator> const> ConstPtr;

}; // struct thermal_msg_

typedef ::t8_package::thermal_msg_<std::allocator<void> > thermal_msg;

typedef boost::shared_ptr< ::t8_package::thermal_msg > thermal_msgPtr;
typedef boost::shared_ptr< ::t8_package::thermal_msg const> thermal_msgConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::t8_package::thermal_msg_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::t8_package::thermal_msg_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace t8_package

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'sensor_msgs': ['/opt/ros/indigo/share/sensor_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 't8_package': ['/home/jmdbo/TRSA/src/t8_package/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::t8_package::thermal_msg_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::t8_package::thermal_msg_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::t8_package::thermal_msg_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::t8_package::thermal_msg_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::t8_package::thermal_msg_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::t8_package::thermal_msg_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::t8_package::thermal_msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "a39aa23240fd1bc7d31d54704ff73af1";
  }

  static const char* value(const ::t8_package::thermal_msg_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xa39aa23240fd1bc7ULL;
  static const uint64_t static_value2 = 0xd31d54704ff73af1ULL;
};

template<class ContainerAllocator>
struct DataType< ::t8_package::thermal_msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "t8_package/thermal_msg";
  }

  static const char* value(const ::t8_package::thermal_msg_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::t8_package::thermal_msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n\
int8 id\n\
int8 temp\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
";
  }

  static const char* value(const ::t8_package::thermal_msg_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::t8_package::thermal_msg_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.id);
      stream.next(m.temp);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct thermal_msg_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::t8_package::thermal_msg_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::t8_package::thermal_msg_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "id: ";
    Printer<int8_t>::stream(s, indent + "  ", v.id);
    s << indent << "temp: ";
    Printer<int8_t>::stream(s, indent + "  ", v.temp);
  }
};

} // namespace message_operations
} // namespace ros

#endif // T8_PACKAGE_MESSAGE_THERMAL_MSG_H
