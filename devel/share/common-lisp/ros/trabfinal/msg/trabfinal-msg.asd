
(cl:in-package :asdf)

(defsystem "trabfinal-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "imagePosUAV" :depends-on ("_package_imagePosUAV"))
    (:file "_package_imagePosUAV" :depends-on ("_package"))
    (:file "controlUAV" :depends-on ("_package_controlUAV"))
    (:file "_package_controlUAV" :depends-on ("_package"))
    (:file "gpsXY" :depends-on ("_package_gpsXY"))
    (:file "_package_gpsXY" :depends-on ("_package"))
    (:file "altitudeUAV" :depends-on ("_package_altitudeUAV"))
    (:file "_package_altitudeUAV" :depends-on ("_package"))
  ))