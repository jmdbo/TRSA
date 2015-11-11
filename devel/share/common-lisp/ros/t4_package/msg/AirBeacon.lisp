; Auto-generated. Do not edit!


(cl:in-package t4_package-msg)


;//! \htmlinclude AirBeacon.msg.html

(cl:defclass <AirBeacon> (roslisp-msg-protocol:ros-message)
  ((mode
    :reader mode
    :initarg :mode
    :type cl:fixnum
    :initform 0))
)

(cl:defclass AirBeacon (<AirBeacon>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <AirBeacon>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'AirBeacon)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name t4_package-msg:<AirBeacon> is deprecated: use t4_package-msg:AirBeacon instead.")))

(cl:ensure-generic-function 'mode-val :lambda-list '(m))
(cl:defmethod mode-val ((m <AirBeacon>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader t4_package-msg:mode-val is deprecated.  Use t4_package-msg:mode instead.")
  (mode m))
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql '<AirBeacon>)))
    "Constants for message type '<AirBeacon>"
  '((:HEAT . 1)
    (:IDLE . 0)
    (:COOL . -1))
)
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql 'AirBeacon)))
    "Constants for message type 'AirBeacon"
  '((:HEAT . 1)
    (:IDLE . 0)
    (:COOL . -1))
)
(cl:defmethod roslisp-msg-protocol:serialize ((msg <AirBeacon>) ostream)
  "Serializes a message object of type '<AirBeacon>"
  (cl:let* ((signed (cl:slot-value msg 'mode)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <AirBeacon>) istream)
  "Deserializes a message object of type '<AirBeacon>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'mode) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<AirBeacon>)))
  "Returns string type for a message object of type '<AirBeacon>"
  "t4_package/AirBeacon")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'AirBeacon)))
  "Returns string type for a message object of type 'AirBeacon"
  "t4_package/AirBeacon")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<AirBeacon>)))
  "Returns md5sum for a message object of type '<AirBeacon>"
  "73e1025c841acf0806d97811f148dbdc")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'AirBeacon)))
  "Returns md5sum for a message object of type 'AirBeacon"
  "73e1025c841acf0806d97811f148dbdc")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<AirBeacon>)))
  "Returns full string definition for message of type '<AirBeacon>"
  (cl:format cl:nil "int8 HEAT = 1~%int8 IDLE = 0~%int8 COOL = -1~%~%int8 mode~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'AirBeacon)))
  "Returns full string definition for message of type 'AirBeacon"
  (cl:format cl:nil "int8 HEAT = 1~%int8 IDLE = 0~%int8 COOL = -1~%~%int8 mode~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <AirBeacon>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <AirBeacon>))
  "Converts a ROS message object to a list"
  (cl:list 'AirBeacon
    (cl:cons ':mode (mode msg))
))
