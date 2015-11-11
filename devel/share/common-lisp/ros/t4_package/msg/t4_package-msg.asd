
(cl:in-package :asdf)

(defsystem "t4_package-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "AirBeacon" :depends-on ("_package_AirBeacon"))
    (:file "_package_AirBeacon" :depends-on ("_package"))
  ))