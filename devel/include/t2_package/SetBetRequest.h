// Generated by gencpp from file t2_package/SetBetRequest.msg
// DO NOT EDIT!


#ifndef T2_PACKAGE_MESSAGE_SETBETREQUEST_H
#define T2_PACKAGE_MESSAGE_SETBETREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace t2_package
{
template <class ContainerAllocator>
struct SetBetRequest_
{
  typedef SetBetRequest_<ContainerAllocator> Type;

  SetBetRequest_()
    : player_id(0)
    , bet(0)  {
    }
  SetBetRequest_(const ContainerAllocator& _alloc)
    : player_id(0)
    , bet(0)  {
    }



   typedef uint8_t _player_id_type;
  _player_id_type player_id;

   typedef uint8_t _bet_type;
  _bet_type bet;




  typedef boost::shared_ptr< ::t2_package::SetBetRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::t2_package::SetBetRequest_<ContainerAllocator> const> ConstPtr;

}; // struct SetBetRequest_

typedef ::t2_package::SetBetRequest_<std::allocator<void> > SetBetRequest;

typedef boost::shared_ptr< ::t2_package::SetBetRequest > SetBetRequestPtr;
typedef boost::shared_ptr< ::t2_package::SetBetRequest const> SetBetRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::t2_package::SetBetRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::t2_package::SetBetRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace t2_package

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 't2_package': ['/home/jmdbo/trsa_ws/src/t2_package/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::t2_package::SetBetRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::t2_package::SetBetRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::t2_package::SetBetRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::t2_package::SetBetRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::t2_package::SetBetRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::t2_package::SetBetRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::t2_package::SetBetRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "822fe7b26148aa78f7a130098e5f9cfb";
  }

  static const char* value(const ::t2_package::SetBetRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x822fe7b26148aa78ULL;
  static const uint64_t static_value2 = 0xf7a130098e5f9cfbULL;
};

template<class ContainerAllocator>
struct DataType< ::t2_package::SetBetRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "t2_package/SetBetRequest";
  }

  static const char* value(const ::t2_package::SetBetRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::t2_package::SetBetRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "uint8 player_id\n\
uint8 bet\n\
";
  }

  static const char* value(const ::t2_package::SetBetRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::t2_package::SetBetRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.player_id);
      stream.next(m.bet);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct SetBetRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::t2_package::SetBetRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::t2_package::SetBetRequest_<ContainerAllocator>& v)
  {
    s << indent << "player_id: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.player_id);
    s << indent << "bet: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.bet);
  }
};

} // namespace message_operations
} // namespace ros

#endif // T2_PACKAGE_MESSAGE_SETBETREQUEST_H