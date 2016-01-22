;; Auto-generated. Do not edit!


(when (boundp 'kelp_ros::ServoControl)
  (if (not (find-package "KELP_ROS"))
    (make-package "KELP_ROS"))
  (shadow 'ServoControl (find-package "KELP_ROS")))
(unless (find-package "KELP_ROS::SERVOCONTROL")
  (make-package "KELP_ROS::SERVOCONTROL"))
(unless (find-package "KELP_ROS::SERVOCONTROLREQUEST")
  (make-package "KELP_ROS::SERVOCONTROLREQUEST"))
(unless (find-package "KELP_ROS::SERVOCONTROLRESPONSE")
  (make-package "KELP_ROS::SERVOCONTROLRESPONSE"))

(in-package "ROS")





(defclass kelp_ros::ServoControlRequest
  :super ros::object
  :slots (_axis _angle ))

(defmethod kelp_ros::ServoControlRequest
  (:init
   (&key
    ((:axis __axis) (make-array 3 :initial-element nil :element-type :object))
    ((:angle __angle) 0.0)
    )
   (send-super :init)
   (setq _axis __axis)
   (setq _angle (float __angle))
   self)
  (:axis
   (&optional __axis)
   (if __axis (setq _axis __axis)) _axis)
  (:angle
   (&optional __angle)
   (if __angle (setq _angle __angle)) _angle)
  (:serialization-length
   ()
   (+
    ;; bool[3] _axis
    (* 1    3)
    ;; float32 _angle
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool[3] _axis
     (dotimes (i 3)
       (if (elt _axis i) (write-byte -1 s) (write-byte 0 s))
       )
     ;; float32 _angle
       (sys::poke _angle (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool[3] _axis
   (dotimes (i (length _axis))
     (setf (elt _axis i) (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
     )
   ;; float32 _angle
     (setq _angle (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(defclass kelp_ros::ServoControlResponse
  :super ros::object
  :slots (_result ))

(defmethod kelp_ros::ServoControlResponse
  (:init
   (&key
    ((:result __result) nil)
    )
   (send-super :init)
   (setq _result __result)
   self)
  (:result
   (&optional __result)
   (if __result (setq _result __result)) _result)
  (:serialization-length
   ()
   (+
    ;; bool _result
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _result
       (if _result (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _result
     (setq _result (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass kelp_ros::ServoControl
  :super ros::object
  :slots ())

(setf (get kelp_ros::ServoControl :md5sum-) "72af5ec18b305597075cd2db6d215c26")
(setf (get kelp_ros::ServoControl :datatype-) "kelp_ros/ServoControl")
(setf (get kelp_ros::ServoControl :request) kelp_ros::ServoControlRequest)
(setf (get kelp_ros::ServoControl :response) kelp_ros::ServoControlResponse)

(defmethod kelp_ros::ServoControlRequest
  (:response () (instance kelp_ros::ServoControlResponse :init)))

(setf (get kelp_ros::ServoControlRequest :md5sum-) "72af5ec18b305597075cd2db6d215c26")
(setf (get kelp_ros::ServoControlRequest :datatype-) "kelp_ros/ServoControlRequest")
(setf (get kelp_ros::ServoControlRequest :definition-)
      "bool[3] axis
float32 angle
---
bool result

")

(setf (get kelp_ros::ServoControlResponse :md5sum-) "72af5ec18b305597075cd2db6d215c26")
(setf (get kelp_ros::ServoControlResponse :datatype-) "kelp_ros/ServoControlResponse")
(setf (get kelp_ros::ServoControlResponse :definition-)
      "bool[3] axis
float32 angle
---
bool result

")



(provide :kelp_ros/ServoControl "72af5ec18b305597075cd2db6d215c26")


