all: compile jar

bin:
	mkdir bin

compile: bin
	javac -d bin src/Controller.java src/Main.java src/TCPClient.java

jar:
	jar cfm ../gui.jar Manifest.mf -C src . -C bin . -C images .
