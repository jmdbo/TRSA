; Auto-generated. Do not edit!


(cl:in-package trabfinal-msg)


;//! \htmlinclude imagePosUAV.msg.html

(cl:defclass <imagePosUAV> (roslisp-msg-protocol:ros-message)
  ((xCenterUAV
    :reader xCenterUAV
    :initarg :xCenterUAV
    :type cl:integer
    :initform 0)
   (yCenterUAV
    :reader yCenterUAV
    :initarg :yCenterUAV
    :type cl:integer
    :initform 0)
   (xCenterImg
    :reader xCenterImg
    :initarg :xCenterImg
    :type cl:integer
    :initform 0)
   (yCenterImg
    :reader yCenterImg
    :initarg :yCenterImg
    :type cl:integer
    :initform 0))
)

(cl:defclass imagePosUAV (<imagePosUAV>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <imagePosUAV>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'imagePosUAV)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name trabfinal-msg:<imagePosUAV> is deprecated: use trabfinal-msg:imagePosUAV instead.")))

(cl:ensure-generic-function 'xCenterUAV-val :lambda-list '(m))
(cl:defmethod xCenterUAV-val ((m <imagePosUAV>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader trabfinal-msg:xCenterUAV-val is deprecated.  Use trabfinal-msg:xCenterUAV instead.")
  (xCenterUAV m))

(cl:ensure-generic-function 'yCenterUAV-val :lambda-list '(m))
(cl:defmethod yCenterUAV-val ((m <imagePosUAV>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader trabfinal-msg:yCenterUAV-val is deprecated.  Use trabfinal-msg:yCenterUAV instead.")
  (yCenterUAV m))

(cl:ensure-generic-function 'xCenterImg-val :lambda-list '(m))
(cl:defmethod xCenterImg-val ((m <imagePosUAV>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader trabfinal-msg:xCenterImg-val is deprecated.  Use trabfinal-msg:xCenterImg instead.")
  (xCenterImg m))

(cl:ensure-generic-function 'yCenterImg-val :lambda-list '(m))
(cl:defmethod yCenterImg-val ((m <imagePosUAV>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader trabfinal-msg:yCenterImg-val is deprecated.  Use trabfinal-msg:yCenterImg instead.")
  (yCenterImg m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <imagePosUAV>) ostream)
  "Serializes a message object of type '<imagePosUAV>"
  (cl:let* ((signed (cl:slot-value msg 'xCenterUAV)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'yCenterUAV)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'xCenterImg)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'yCenterImg)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <imagePosUAV>) istream)
  "Deserializes a message object of type '<imagePosUAV>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'xCenterUAV) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'yCenterUAV) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'xCenterImg) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'yCenterImg) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<imagePosUAV>)))
  "Returns string type for a message object of type '<imagePosUAV>"
  "trabfinal/imagePosUAV")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'imagePosUAV)))
  "Returns string type for a message object of type 'imagePosUAV"
  "trabfinal/imagePosUAV")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<imagePosUAV>)))
  "Returns md5sum for a message object of type '<imagePosUAV>"
  "adb802c27b6276c3ccbc3f94082c196a")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'imagePosUAV)))
  "Returns md5sum for a message object of type 'imagePosUAV"
  "adb802c27b6276c3ccbc3f94082c196a")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<imagePosUAV>)))
  "Returns full string definition for message of type '<imagePosUAV>"
  (cl:format cl:nil "int32 xCenterUAV~%int32 yCenterUAV~%int32 xCenterImg~%int32 yCenterImg~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'imagePosUAV)))
  "Returns full string definition for message of type 'imagePosUAV"
  (cl:format cl:nil "int32 xCenterUAV~%int32 yCenterUAV~%int32 xCenterImg~%int32 yCenterImg~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <imagePosUAV>))
  (cl:+ 0
     4
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <imagePosUAV>))
  "Converts a ROS message object to a list"
  (cl:list 'imagePosUAV
    (cl:cons ':xCenterUAV (xCenterUAV msg))
    (cl:cons ':yCenterUAV (yCenterUAV msg))
    (cl:cons ':xCenterImg (xCenterImg msg))
    (cl:cons ':yCenterImg (yCenterImg msg))
))
