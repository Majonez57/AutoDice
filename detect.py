import cv2
import numpy as np
import os.path
from time import sleep as zzz


def apply_brightness_contrast(input_img, brightness = 0, contrast = 0):    
    if brightness != 0:
        if brightness > 0:
            shadow = brightness
            highlight = 255
        else:
            shadow = 0
            highlight = 255 + brightness
        alpha_b = (highlight - shadow)/255
        gamma_b = shadow
        
        buf = cv2.addWeighted(input_img, alpha_b, input_img, 0, gamma_b)
    else:
        buf = input_img.copy()
    
    if contrast != 0:
        f = 131*(contrast + 127)/(127*(131-contrast))
        alpha_c = f
        gamma_c = 127*(1-f)
        
        buf = cv2.addWeighted(buf, alpha_c, buf, 0, gamma_c)

    return buf

cam = cv2.VideoCapture(1)
if os.path.isfile("./base.png"):
    base = cv2.imread("base.png")
else:
    print("Base image not found. Capturing")

    result, base = cam.read()


    if not result:
        print("No image found. Try again")
        exit()

    print("Base Image captured.")
    cv2.imwrite("base.png", base)

    zzz(3)

result, new = cam.read()

base[:,:,2] =np.zeros([base.shape[0], base.shape[1]])
new[:,:,2] = np.zeros([new.shape[0], new.shape[1]])
cv2.imshow("in", new)

diff2 = cv2.subtract(base, new)
diff= cv2.subtract(new, base)


cmb1 = cv2.add(diff, diff2)
cmb = apply_brightness_contrast(cmb1, 45, 20)
cmb = cv2.cvtColor(cmb, cv2.COLOR_RGB2GRAY)
cmb = cmb[90:410,90:510]
cv2.imshow("comb", cmb)


cv2.waitKey(0)