import random
import sys
import serial.tools.list_ports
import time
from Adafruit_IO import MQTTClient

AIO_FEED_IDs = ["button1", "button2"]
AIO_USERNAME = "Kietlun9302"
AIO_KEY = "aio_nWgL63JKpMGPYqz5CZTATiOvzWpq"


def connected(client):
    print("Ket noi thanh cong ...")
    for topic in AIO_FEED_IDs:
        client.subscribe(topic)
    client.subscribe(AIO_FEED_IDs)


def subscribe(client, userdata, mid, granted_qos):
    print("Subscribe thanh cong ...")


def disconnected(client):
    print("Ngat ket noi ...")
    sys.exit(1)


def message(client, feed_id, payload):
    print("Nhan du lieu: " + payload + " , feed id: " + feed_id)

def getPort():
    ports = serial.tools.list_ports.comports()
    N = len(ports)
    commPort = "None"
    for i in range(0, N):
        port = ports[i]
        print(port)
        strPort = str(port)
        if "usbserial" in strPort: #tùy theo tên port trên PC
            splitPort = strPort.split(" ")
            commPort = (splitPort[0])
    return commPort


ser = serial . Serial(port=getPort(), baudrate=115200)

client = MQTTClient(AIO_USERNAME, AIO_KEY)
client.on_connect = connected
client.on_disconnect = disconnected
client.on_message = message
client.on_subscribe = subscribe
client.connect()
client.loop_background()

counter = 5
while True:
    counter = counter - 1
    if counter <= 0:
        counter = 10000
        # TODO
        print("randing value publishing...")
        print("Humidity")
        humi = random.randint(50, 70)
        client.publish("cambien2", humi)
        time.sleep(30)
    pass
