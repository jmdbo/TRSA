// Generated by gencpp from file t4_package/AirBeacon.msg
// DO NOT EDIT!


#ifndef T4_PACKAGE_MESSAGE_AIRBEACON_H
#define T4_PACKAGE_MESSAGE_AIRBEACON_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace t4_package
{
template <class ContainerAllocator>
struct AirBeacon_
{
  typedef AirBeacon_<ContainerAllocator> Type;

  AirBeacon_()
    : mode(0)  {
    }
  AirBeacon_(const ContainerAllocator& _alloc)
    : mode(0)  {
    }



   typedef int8_t _mode_type;
  _mode_type mode;


    enum { HEAT = 1 };
     enum { IDLE = 0 };
     enum { COOL = -1 };
 

  typedef boost::shared_ptr< ::t4_package::AirBeacon_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::t4_package::AirBeacon_<ContainerAllocator> const> ConstPtr;

}; // struct AirBeacon_

typedef ::t4_package::AirBeacon_<std::allocator<void> > AirBeacon;

typedef boost::shared_ptr< ::t4_package::AirBeacon > AirBeaconPtr;
typedef boost::shared_ptr< ::t4_package::AirBeacon const> AirBeaconConstPtr;

// constants requiring out of line definition

   

   

   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::t4_package::AirBeacon_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::t4_package::AirBeacon_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace t4_package

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'t4_package': ['/home/jmdbo/TRSA/src/t4_package/msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::t4_package::AirBeacon_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::t4_package::AirBeacon_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::t4_package::AirBeacon_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::t4_package::AirBeacon_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::t4_package::AirBeacon_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::t4_package::AirBeacon_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::t4_package::AirBeacon_<ContainerAllocator> >
{
  static const char* value()
  {
    return "73e1025c841acf0806d97811f148dbdc";
  }

  static const char* value(const ::t4_package::AirBeacon_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x73e1025c841acf08ULL;
  static const uint64_t static_value2 = 0x06d97811f148dbdcULL;
};

template<class ContainerAllocator>
struct DataType< ::t4_package::AirBeacon_<ContainerAllocator> >
{
  static const char* value()
  {
    return "t4_package/AirBeacon";
  }

  static const char* value(const ::t4_package::AirBeacon_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::t4_package::AirBeacon_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int8 HEAT = 1\n\
int8 IDLE = 0\n\
int8 COOL = -1\n\
\n\
int8 mode\n\
";
  }

  static const char* value(const ::t4_package::AirBeacon_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::t4_package::AirBeacon_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.mode);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct AirBeacon_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::t4_package::AirBeacon_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::t4_package::AirBeacon_<ContainerAllocator>& v)
  {
    s << indent << "mode: ";
    Printer<int8_t>::stream(s, indent + "  ", v.mode);
  }
};

} // namespace message_operations
} // namespace ros

#endif // T4_PACKAGE_MESSAGE_AIRBEACON_H
