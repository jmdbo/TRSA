; Auto-generated. Do not edit!


(cl:in-package t2_package-msg)


;//! \htmlinclude GameStatus.msg.html

(cl:defclass <GameStatus> (roslisp-msg-protocol:ros-message)
  ((status
    :reader status
    :initarg :status
    :type cl:fixnum
    :initform 0)
   (score
    :reader score
    :initarg :score
    :type (cl:vector cl:fixnum)
   :initform (cl:make-array 2 :element-type 'cl:fixnum :initial-element 0))
   (winner
    :reader winner
    :initarg :winner
    :type cl:fixnum
    :initform 0))
)

(cl:defclass GameStatus (<GameStatus>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <GameStatus>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'GameStatus)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name t2_package-msg:<GameStatus> is deprecated: use t2_package-msg:GameStatus instead.")))

(cl:ensure-generic-function 'status-val :lambda-list '(m))
(cl:defmethod status-val ((m <GameStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader t2_package-msg:status-val is deprecated.  Use t2_package-msg:status instead.")
  (status m))

(cl:ensure-generic-function 'score-val :lambda-list '(m))
(cl:defmethod score-val ((m <GameStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader t2_package-msg:score-val is deprecated.  Use t2_package-msg:score instead.")
  (score m))

(cl:ensure-generic-function 'winner-val :lambda-list '(m))
(cl:defmethod winner-val ((m <GameStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader t2_package-msg:winner-val is deprecated.  Use t2_package-msg:winner instead.")
  (winner m))
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql '<GameStatus>)))
    "Constants for message type '<GameStatus>"
  '((:NEW_BET_SESSION . 0)
    (:BET_SESSION_RESULT . 1)
    (:GAME_FINISHED . 2))
)
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql 'GameStatus)))
    "Constants for message type 'GameStatus"
  '((:NEW_BET_SESSION . 0)
    (:BET_SESSION_RESULT . 1)
    (:GAME_FINISHED . 2))
)
(cl:defmethod roslisp-msg-protocol:serialize ((msg <GameStatus>) ostream)
  "Serializes a message object of type '<GameStatus>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'status)) ostream)
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) ele) ostream))
   (cl:slot-value msg 'score))
  (cl:let* ((signed (cl:slot-value msg 'winner)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <GameStatus>) istream)
  "Deserializes a message object of type '<GameStatus>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'status)) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'score) (cl:make-array 2))
  (cl:let ((vals (cl:slot-value msg 'score)))
    (cl:dotimes (i 2)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:aref vals i)) (cl:read-byte istream))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'winner) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<GameStatus>)))
  "Returns string type for a message object of type '<GameStatus>"
  "t2_package/GameStatus")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GameStatus)))
  "Returns string type for a message object of type 'GameStatus"
  "t2_package/GameStatus")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<GameStatus>)))
  "Returns md5sum for a message object of type '<GameStatus>"
  "6f9d99196b01e60e431da38c3d5b9152")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'GameStatus)))
  "Returns md5sum for a message object of type 'GameStatus"
  "6f9d99196b01e60e431da38c3d5b9152")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<GameStatus>)))
  "Returns full string definition for message of type '<GameStatus>"
  (cl:format cl:nil "# Constant Definition for game status~%uint8 NEW_BET_SESSION = 0~%uint8 BET_SESSION_RESULT = 1~%uint8 GAME_FINISHED = 2~%~%uint8 status~%uint8[2] score # score[0] = ROS Player; score[1] = Human Player~%int8 winner # -1 = Not defined (tie); 0 = ROS Player; 1 = Human Player~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'GameStatus)))
  "Returns full string definition for message of type 'GameStatus"
  (cl:format cl:nil "# Constant Definition for game status~%uint8 NEW_BET_SESSION = 0~%uint8 BET_SESSION_RESULT = 1~%uint8 GAME_FINISHED = 2~%~%uint8 status~%uint8[2] score # score[0] = ROS Player; score[1] = Human Player~%int8 winner # -1 = Not defined (tie); 0 = ROS Player; 1 = Human Player~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <GameStatus>))
  (cl:+ 0
     1
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'score) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 1)))
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <GameStatus>))
  "Converts a ROS message object to a list"
  (cl:list 'GameStatus
    (cl:cons ':status (status msg))
    (cl:cons ':score (score msg))
    (cl:cons ':winner (winner msg))
))
