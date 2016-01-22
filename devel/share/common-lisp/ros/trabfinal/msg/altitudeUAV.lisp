; Auto-generated. Do not edit!


(cl:in-package trabfinal-msg)


;//! \htmlinclude altitudeUAV.msg.html

(cl:defclass <altitudeUAV> (roslisp-msg-protocol:ros-message)
  ((altitude
    :reader altitude
    :initarg :altitude
    :type cl:float
    :initform 0.0))
)

(cl:defclass altitudeUAV (<altitudeUAV>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <altitudeUAV>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'altitudeUAV)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name trabfinal-msg:<altitudeUAV> is deprecated: use trabfinal-msg:altitudeUAV instead.")))

(cl:ensure-generic-function 'altitude-val :lambda-list '(m))
(cl:defmethod altitude-val ((m <altitudeUAV>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader trabfinal-msg:altitude-val is deprecated.  Use trabfinal-msg:altitude instead.")
  (altitude m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <altitudeUAV>) ostream)
  "Serializes a message object of type '<altitudeUAV>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'altitude))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <altitudeUAV>) istream)
  "Deserializes a message object of type '<altitudeUAV>"
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
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<altitudeUAV>)))
  "Returns string type for a message object of type '<altitudeUAV>"
  "trabfinal/altitudeUAV")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'altitudeUAV)))
  "Returns string type for a message object of type 'altitudeUAV"
  "trabfinal/altitudeUAV")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<altitudeUAV>)))
  "Returns md5sum for a message object of type '<altitudeUAV>"
  "42af7eb0aaf91dc07d6880f800cabbb3")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'altitudeUAV)))
  "Returns md5sum for a message object of type 'altitudeUAV"
  "42af7eb0aaf91dc07d6880f800cabbb3")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<altitudeUAV>)))
  "Returns full string definition for message of type '<altitudeUAV>"
  (cl:format cl:nil "float64 altitude~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'altitudeUAV)))
  "Returns full string definition for message of type 'altitudeUAV"
  (cl:format cl:nil "float64 altitude~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <altitudeUAV>))
  (cl:+ 0
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <altitudeUAV>))
  "Converts a ROS message object to a list"
  (cl:list 'altitudeUAV
    (cl:cons ':altitude (altitude msg))
))
