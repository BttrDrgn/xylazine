#pragma once

class bFile
{
public:
	int unk_0;
	int unk_4;
	int unk_8;
	int unk_12;
	int unk_16;
	int unk_20;
	int unk_24;

	bFile(char* path, int a2);
	void bClose(int a2);

};

bFile* bOpen(char* path, int a2);