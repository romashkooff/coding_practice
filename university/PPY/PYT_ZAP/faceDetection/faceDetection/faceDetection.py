import cv2

face_cascade = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_frontalface_default.xml')

webcam = cv2.VideoCapture(0)

while True:
    ret, frame = webcam.read()
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    faces = face_cascade.detectMultiScale(gray, minSize=(50, 50), minNeighbors=10,  scaleFactor=1.1, flags=cv2.CASCADE_SCALE_IMAGE)
    for (x, y, w, h) in faces: cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 255, 0), 1)
    cv2.putText(frame, 'Press q to exit', (30, 50), cv2.FONT_HERSHEY_COMPLEX, 1, (0, 255, 0), 2)
    cv2.imshow('Webcam Face Detection', frame)
    if cv2.waitKey(1) == ord('q'): break
webcam.release()
