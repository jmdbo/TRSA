; Auto-generated. Do not edit!


(cl:in-package t4_package-srv)


;//! \htmlinclude DesiredTemperature-request.msg.html

(cl:defclass <DesiredTemperature-request> (roslisp-msg-protocol:ros-message)
  ((temperature
    :reader temperature
    :initarg :temperature
    :type cl:float
    :initform 0.0))
)

(cl:defclass DesiredTemperature-request (<DesiredTemperature-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <DesiredTemperature-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'DesiredTemperature-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name t4_package-srv:<DesiredTemperature-request> is deprecated: use t4_package-srv:DesiredTemperature-request instead.")))

(cl:ensure-generic-function 'temperature-val :lambda-list '(m))
(cl:defmethod temperature-val ((m <DesiredTemperature-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader t4_package-srv:temperature-val is deprecated.  Use t4_package-srv:temperature instead.")
  (temperature m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <DesiredTemperature-request>) ostream)
  "Serializes a message object of type '<DesiredTemperature-request>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'temperature))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <DesiredTemperature-request>) istream)
  "Deserializes a message object of type '<DesiredTemperature-request>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'temperature) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<DesiredTemperature-request>)))
  "Returns string type for a service object of type '<DesiredTemperature-request>"
  "t4_package/DesiredTemperatureRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'DesiredTemperature-request)))
  "Returns string type for a service object of type 'DesiredTemperature-request"
  "t4_package/DesiredTemperatureRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<DesiredTemperature-request>)))
  "Returns md5sum for a message object of type '<DesiredTemperature-request>"
  "739e57d5bb0983212540786c5e3bf89e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'DesiredTemperature-request)))
  "Returns md5sum for a message object of type 'DesiredTemperature-request"
  "739e57d5bb0983212540786c5e3bf89e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<DesiredTemperature-request>)))
  "Returns full string definition for message of type '<DesiredTemperature-request>"
  (cl:format cl:nil "float32 temperature~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'DesiredTemperature-request)))
  "Returns full string definition for message of type 'DesiredTemperature-request"
  (cl:format cl:nil "float32 temperature~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <DesiredTemperature-request>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <DesiredTemperature-request>))
  "Converts a ROS message object to a list"
  (cl:list 'DesiredTemperature-request
    (cl:cons ':temperature (temperature msg))
))
;//! \htmlinclude DesiredTemperature-response.msg.html

(cl:defclass <DesiredTemperature-response> (roslisp-msg-protocol:ros-message)
  ((result
    :reader result
    :initarg :result
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass DesiredTemperature-response (<DesiredTemperature-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <DesiredTemperature-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'DesiredTemperature-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name t4_package-srv:<DesiredTemperature-response> is deprecated: use t4_package-srv:DesiredTemperature-response instead.")))

(cl:ensure-generic-function 'result-val :lambda-list '(m))
(cl:defmethod result-val ((m <DesiredTemperature-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader t4_package-srv:result-val is deprecated.  Use t4_package-srv:result instead.")
  (result m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <DesiredTemperature-response>) ostream)
  "Serializes a message object of type '<DesiredTemperature-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'result) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <DesiredTemperature-response>) istream)
  "Deserializes a message object of type '<DesiredTemperature-response>"
    (cl:setf (cl:slot-value msg 'result) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<DesiredTemperature-response>)))
  "Returns string type for a service object of type '<DesiredTemperature-response>"
  "t4_package/DesiredTemperatureResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'DesiredTemperature-response)))
  "Returns string type for a service object of type 'DesiredTemperature-response"
  "t4_package/DesiredTemperatureResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<DesiredTemperature-response>)))
  "Returns md5sum for a message object of type '<DesiredTemperature-response>"
  "739e57d5bb0983212540786c5e3bf89e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'DesiredTemperature-response)))
  "Returns md5sum for a message object of type 'DesiredTemperature-response"
  "739e57d5bb0983212540786c5e3bf89e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<DesiredTemperature-response>)))
  "Returns full string definition for message of type '<DesiredTemperature-response>"
  (cl:format cl:nil "bool result~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'DesiredTemperature-response)))
  "Returns full string definition for message of type 'DesiredTemperature-response"
  (cl:format cl:nil "bool result~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <DesiredTemperature-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <DesiredTemperature-response>))
  "Converts a ROS message object to a list"
  (cl:list 'DesiredTemperature-response
    (cl:cons ':result (result msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'DesiredTemperature)))
  'DesiredTemperature-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'DesiredTemperature)))
  'DesiredTemperature-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'DesiredTemperature)))
  "Returns string type for a service object of type '<DesiredTemperature>"
  "t4_package/DesiredTemperature")