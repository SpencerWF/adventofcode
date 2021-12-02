import serial
# from serial.tools import list_ports

def select_serial():
    available_devices = get_serial_list()



def get_serial_list():
    """ Scan for serial devices, then compare to previously input device name
    """
    return tools.list_ports.comports()

    # for i in range(256):
    #     try:
    #         s = serial.Serial(i)
    #         available.append( (i, s.portstr))
    #         s.close()
    #     except serial.SerialException:
    #         pass
    # return available


if __name__ == "__main__":
    f = open("input1.txt", "r")
    contents = f.read()
    floor = follow_guide(contents)
    print(f"Floor is: {floor}")