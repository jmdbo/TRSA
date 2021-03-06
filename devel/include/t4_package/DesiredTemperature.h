// Generated by gencpp from file t4_package/DesiredTemperature.msg
// DO NOT EDIT!


#ifndef T4_PACKAGE_MESSAGE_DESIREDTEMPERATURE_H
#define T4_PACKAGE_MESSAGE_DESIREDTEMPERATURE_H

#include <ros/service_traits.h>


#include <t4_package/DesiredTemperatureRequest.h>
#include <t4_package/DesiredTemperatureResponse.h>


namespace t4_package
{

struct DesiredTemperature
{

typedef DesiredTemperatureRequest Request;
typedef DesiredTemperatureResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct DesiredTemperature
} // namespace t4_package


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::t4_package::DesiredTemperature > {
  static const char* value()
  {
    return "739e57d5bb0983212540786c5e3bf89e";
  }

  static const char* value(const ::t4_package::DesiredTemperature&) { return value(); }
};

template<>
struct DataType< ::t4_package::DesiredTemperature > {
  static const char* value()
  {
    return "t4_package/DesiredTemperature";
  }

  static const char* value(const ::t4_package::DesiredTemperature&) { return value(); }
};


// service_traits::MD5Sum< ::t4_package::DesiredTemperatureRequest> should match 
// service_traits::MD5Sum< ::t4_package::DesiredTemperature > 
template<>
struct MD5Sum< ::t4_package::DesiredTemperatureRequest>
{
  static const char* value()
  {
    return MD5Sum< ::t4_package::DesiredTemperature >::value();
  }
  static const char* value(const ::t4_package::DesiredTemperatureRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::t4_package::DesiredTemperatureRequest> should match 
// service_traits::DataType< ::t4_package::DesiredTemperature > 
template<>
struct DataType< ::t4_package::DesiredTemperatureRequest>
{
  static const char* value()
  {
    return DataType< ::t4_package::DesiredTemperature >::value();
  }
  static const char* value(const ::t4_package::DesiredTemperatureRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::t4_package::DesiredTemperatureResponse> should match 
// service_traits::MD5Sum< ::t4_package::DesiredTemperature > 
template<>
struct MD5Sum< ::t4_package::DesiredTemperatureResponse>
{
  static const char* value()
  {
    return MD5Sum< ::t4_package::DesiredTemperature >::value();
  }
  static const char* value(const ::t4_package::DesiredTemperatureResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::t4_package::DesiredTemperatureResponse> should match 
// service_traits::DataType< ::t4_package::DesiredTemperature > 
template<>
struct DataType< ::t4_package::DesiredTemperatureResponse>
{
  static const char* value()
  {
    return DataType< ::t4_package::DesiredTemperature >::value();
  }
  static const char* value(const ::t4_package::DesiredTemperatureResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // T4_PACKAGE_MESSAGE_DESIREDTEMPERATURE_H
