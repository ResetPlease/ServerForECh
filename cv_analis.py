import numpy as np
import cv2

base = "C:\\Users\\User\\AppData\\Local\\Programs\\Python\\Python36\\Lib\\site-packages\\cv2\\data"
def Detect(frame, cascade):
    #face_cascade is loaded
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    detect = cascade.detectMultiScale(
        gray,
        scaleFactor= 1.1,
        minNeighbors= 5,
        minSize=(10, 10))
    return detect


cap = cv2.VideoCapture(0)
face_cascade = cv2.CascadeClassifier(base+'\\haarcascade_frontalface_default.xml')
eye_cascade = cv2.CascadeClassifier(base+"\\haarcascade_eye.xml")
while(True): 
    ret, frame = cap.read()
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    faces = Detect(frame, face_cascade)
    eye = Detect(frame, eye_cascade)
    for (x, y, w, h) in faces:
        cv2.rectangle(frame, (x, y), (x+w, y+h), (255, 255, 0), 2)
    for (x, y, w, h) in eye:
        cv2.rectangle(frame, (x, y), (x+w, y+h), (255, 255, 0), 2)
    cv2.imshow('Frame', frame)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()