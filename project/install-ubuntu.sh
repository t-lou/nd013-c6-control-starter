#! /bin/bash
sudo apt-get install -y libuv1-dev libssl-dev libz-dev
git clone https://github.com/uWebSockets/uWebSockets 
cd uWebSockets
git checkout e94b6e1
mkdir build
cd build
cmake ..
make 
sudo make install
cd ..
cd ..
sudo rm -r uWebSockets
sudo ln -s /usr/lib64/libuWS.so /usr/lib/libuWS.so

sudo apt-get update -y
sudo apt-get install -y gnuplot

rm -rf pid_controller/rpclib
git clone https://github.com/rpclib/rpclib.git pid_controller/rpclib
cd pid_controller/rpclib
cmake .
make -j
cd ../..