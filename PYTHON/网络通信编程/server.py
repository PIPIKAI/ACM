from threading import Thread, Lock
import socket


class Server:
    def __init__(self, ip_addr="192.168.8.103", port_num = 8080):
        self.ip_addr = ip_addr
        self.port_num = port_num
        self.cnt = []
        self.lock = Lock()

    def start_sever(self):
        """启动服务器，并开始监听，每当连接一个客户端，便为他创建一个对应的子线程"""
        server = socket.socket()
        server.bind((self.ip_addr, self.port_num))
        server.listen(1024)
        welcome = "欢迎来到JoonGi的聊天室"
        while True:
            connect, addr = server.accept()
            connect.send(welcome.encode(encoding="utf-8"))
            self.cnt.append({'obj': connect, 'addr': addr})
            recv = Thread(target=self.recv_message, args=(connect,addr))
            recv.start()

    def recv_message(self, connect, addr):
        """子线程函数：接收消息，并广播消息给每个连接的客户端"""
        while True:
            data = connect.recv(1024)
            msg =data.decode(encoding="utf-8")
            self.lock.acquire()
            self.lock.release()
            print(msg)
            for c in self.cnt:
                c['obj'].send(msg.encode(encoding="utf-8"))
            if data.decode(encoding="utf-8") =="拜拜":
                self.cnt.remove({'obj': connect, 'addr': addr})
                break
        connect.close()


def main():
    server = Server()
    server.start_sever()


if __name__ == "__main__":
    main()