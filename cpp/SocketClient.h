#pragma once
namespace MySocketClient {
	class SocketClient {
	public:
		SocketClient() {
			;
		}
		//虚析构函数的细节
		~SocketClient() {
			;
		}
		//客户端初始化, 获取handle上下文
		int cltSocketInit();
		//客户端发报文
		int cltSocketSend(unsigned char *buf, int bufflen);
		//客户端收报文
		int cltSocketRev(unsigned char *buf, int *bufflen);
		//客户端释放资源
		int cltSocketDestroy();
	};
}