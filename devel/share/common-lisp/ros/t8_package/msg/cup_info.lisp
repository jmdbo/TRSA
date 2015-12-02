; Auto-generated. Do not edit!


(cl:in-package t8_package-msg)


;//! \htmlinclude cup_info.msg.html

(cl:defclass <cup_info> (roslisp-msg-protocol:ros-message)
  ((Header
    :reader Header
    :initarg :Header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (Group_number
    :reader Group_number
    :initarg :Group_number
    :type cl:fixnum
    :initform 0)
   (Object_position
    :reader Object_position
    :initarg :Object_position
    :type geometry_msgs-msg:Point
    :initform (cl:make-instance 'geometry_msgs-msg:Point))
   (Bag_name
    :reader Bag_name
    :initarg :Bag_name
    :type cl:string
    :initform "")
   (Thermal_label
    :reader Thermal_label
    :initarg :Thermal_label
    :type cl:fixnum
    :initform 0))
)

(cl:defclass cup_info (<cup_info>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <cup_info>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'cup_info)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name t8_package-msg:<cup_info> is deprecated: use t8_package-msg:cup_info instead.")))

(cl:ensure-generic-function 'Header-val :lambda-list '(m))
(cl:defmethod Header-val ((m <cup_info>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader t8_package-msg:Header-val is deprecated.  Use t8_package-msg:Header instead.")
  (Header m))

(cl:ensure-generic-function 'Group_number-val :lambda-list '(m))
(cl:defmethod Group_number-val ((m <cup_info>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader t8_package-msg:Group_number-val is deprecated.  Use t8_package-msg:Group_number instead.")
  (Group_number m))

(cl:ensure-generic-function 'Object_position-val :lambda-list '(m))
(cl:defmethod Object_position-val ((m <cup_info>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader t8_package-msg:Object_position-val is deprecated.  Use t8_package-msg:Object_position instead.")
  (Object_position m))

(cl:ensure-generic-function 'Bag_name-val :lambda-list '(m))
(cl:defmethod Bag_name-val ((m <cup_info>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader t8_package-msg:Bag_name-val is deprecated.  Use t8_package-msg:Bag_name instead.")
  (Bag_name m))

(cl:ensure-generic-function 'Thermal_label-val :lambda-list '(m))
(cl:defmethod Thermal_label-val ((m <cup_info>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader t8_package-msg:Thermal_label-val is deprecated.  Use t8_package-msg:Thermal_label instead.")
  (Thermal_label m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <cup_info>) ostream)
  "Serializes a message object of type '<cup_info>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'Header) ostream)
  (cl:let* ((signed (cl:slot-value msg 'Group_number)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'Object_position) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'Bag_name))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'Bag_name))
  (cl:let* ((signed (cl:slot-value msg 'Thermal_label)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <cup_info>) istream)
  "Deserializes a message object of type '<cup_info>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'Header) istream)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'Group_number) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'Object_position) istream)
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'Bag_name) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'Bag_name) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'Thermal_label) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<cup_info>)))
  "Returns string type for a message object of type '<cup_info>"
  "t8_package/cup_info")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'cup_info)))
  "Returns string type for a message object of type 'cup_info"
  "t8_package/cup_info")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<cup_info>)))
  "Returns md5sum for a message object of type '<cup_info>"
  "437405b3f313d7278c82c4631f055dec")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'cup_info)))
  "Returns md5sum for a message object of type 'cup_info"
  "437405b3f313d7278c82c4631f055dec")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<cup_info>)))
  "Returns full string definition for message of type '<cup_info>"
  (cl:format cl:nil "Header Header~%int16 Group_number~%geometry_msgs/Point Object_position~%string Bag_name~%int8 Thermal_label~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'cup_info)))
  "Returns full string definition for message of type 'cup_info"
  (cl:format cl:nil "Header Header~%int16 Group_number~%geometry_msgs/Point Object_position~%string Bag_name~%int8 Thermal_label~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <cup_info>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'Header))
     2
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'Object_position))
     4 (cl:length (cl:slot-value msg 'Bag_name))
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <cup_info>))
  "Converts a ROS message object to a list"
  (cl:list 'cup_info
    (cl:cons ':Header (Header msg))
    (cl:cons ':Group_number (Group_number msg))
    (cl:cons ':Object_position (Object_position msg))
    (cl:cons ':Bag_name (Bag_name msg))
    (cl:cons ':Thermal_label (Thermal_label msg))
))
