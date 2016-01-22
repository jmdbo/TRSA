; Auto-generated. Do not edit!


(cl:in-package trabfinal-msg)


;//! \htmlinclude controlUAV.msg.html

(cl:defclass <controlUAV> (roslisp-msg-protocol:ros-message)
  ((altitude
    :reader altitude
    :initarg :altitude
    :type cl:float
    :initform 0.0)
   (angle
    :reader angle
    :initarg :angle
    :type cl:float
    :initform 0.0))
)

(cl:defclass controlUAV (<controlUAV>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <controlUAV>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'controlUAV)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name trabfinal-msg:<controlUAV> is deprecated: use trabfinal-msg:controlUAV instead.")))

(cl:ensure-generic-function 'altitude-val :lambda-list '(m))
(cl:defmethod altitude-val ((m <controlUAV>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader trabfinal-msg:altitude-val is deprecated.  Use trabfinal-msg:altitude instead.")
  (altitude m))

(cl:ensure-generic-function 'angle-val :lambda-list '(m))
(cl:defmethod angle-val ((m <controlUAV>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader trabfinal-msg:angle-val is deprecated.  Use trabfinal-msg:angle instead.")
  (angle m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <controlUAV>) ostream)
  "Serializes a message object of type '<controlUAV>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'altitude))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'angle))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <controlUAV>) istream)
  "Deserializes a message object of type '<controlUAV>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'altitude) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'angle) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<controlUAV>)))
  "Returns string type for a message object of type '<controlUAV>"
  "trabfinal/controlUAV")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'controlUAV)))
  "Returns string type for a message object of type 'controlUAV"
  "trabfinal/controlUAV")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<controlUAV>)))
  "Returns md5sum for a message object of type '<controlUAV>"
  "09d83d88ec2b5cbfb495cf94b70c2bfa")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'controlUAV)))
  "Returns md5sum for a message object of type 'controlUAV"
  "09d83d88ec2b5cbfb495cf94b70c2bfa")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<controlUAV>)))
  "Returns full string definition for message of type '<controlUAV>"
  (cl:format cl:nil "float64 altitude~%float64 angle~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'controlUAV)))
  "Returns full string definition for message of type 'controlUAV"
  (cl:format cl:nil "float64 altitude~%float64 angle~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <controlUAV>))
  (cl:+ 0
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <controlUAV>))
  "Converts a ROS message object to a list"
  (cl:list 'controlUAV
    (cl:cons ':altitude (altitude msg))
    (cl:cons ':angle (angle msg))
))
