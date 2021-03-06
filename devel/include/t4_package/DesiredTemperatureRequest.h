// Generated by gencpp from file t4_package/DesiredTemperatureRequest.msg
// DO NOT EDIT!


#ifndef T4_PACKAGE_MESSAGE_DESIREDTEMPERATUREREQUEST_H
#define T4_PACKAGE_MESSAGE_DESIREDTEMPERATUREREQUEST_H


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
struct DesiredTemperatureRequest_
{
  typedef DesiredTemperatureRequest_<ContainerAllocator> Type;

  DesiredTemperatureRequest_()
    : temperature(0.0)  {
    }
  DesiredTemperatureRequest_(const ContainerAllocator& _alloc)
    : temperature(0.0)  {
    }



   typedef float _temperature_type;
  _temperature_type temperature;




  typedef boost::shared_ptr< ::t4_package::DesiredTemperatureRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::t4_package::DesiredTemperatureRequest_<ContainerAllocator> const> ConstPtr;

}; // struct DesiredTemperatureRequest_

typedef ::t4_package::DesiredTemperatureRequest_<std::allocator<void> > DesiredTemperatureRequest;

typedef boost::shared_ptr< ::t4_package::DesiredTemperatureRequest > DesiredTemperatureRequestPtr;
typedef boost::shared_ptr< ::t4_package::DesiredTemperatureRequest const> DesiredTemperatureRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::t4_package::DesiredTemperatureRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::t4_package::DesiredTemperatureRequest_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::t4_package::DesiredTemperatureRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::t4_package::DesiredTemperatureRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::t4_package::DesiredTemperatureRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::t4_package::DesiredTemperatureRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::t4_package::DesiredTemperatureRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::t4_package::DesiredTemperatureRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::t4_package::DesiredTemperatureRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "694ab1a51fd38693b5cadd94c1ae252d";
  }

  static const char* value(const ::t4_package::DesiredTemperatureRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x694ab1a51fd38693ULL;
  static const uint64_t static_value2 = 0xb5cadd94c1ae252dULL;
};

template<class ContainerAllocator>
struct DataType< ::t4_package::DesiredTemperatureRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "t4_package/DesiredTemperatureRequest";
  }

  static const char* value(const ::t4_package::DesiredTemperatureRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::t4_package::DesiredTemperatureRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32 temperature\n\
";
  }

  static const char* value(const ::t4_package::DesiredTemperatureRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::t4_package::DesiredTemperatureRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.temperature);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct DesiredTemperatureRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::t4_package::DesiredTemperatureRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::t4_package::DesiredTemperatureRequest_<ContainerAllocator>& v)
  {
    s << indent << "temperature: ";
    Printer<float>::stream(s, indent + "  ", v.temperature);
  }
};

} // namespace message_operations
} // namespace ros

#endif // T4_PACKAGE_MESSAGE_DESIREDTEMPERATUREREQUEST_H
