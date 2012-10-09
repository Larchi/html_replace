all:
	g++ main.cpp folderkeeper.cpp htmlreplacer.cpp threadmanager.cpp -I /usr/include -L /usr/lib/ -lboost_system -lboost_thread -lboost_filesystem -lboost_regex  -o html_replace 

