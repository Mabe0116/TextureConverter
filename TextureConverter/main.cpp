#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <Windows.h>
#include "TextureConverter.h"

enum Argument {
	kApplicationPath,
	kFilePath,

	NumArgument
};

int main(int argc,char* argv[]) {
	
	assert(argc >= NumArgument);

	//COM ライブラリの初期化
	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	assert(SUCCEEDED(hr));

	//テクスチャコンバータ
	TextureConverter converter;

	//テクスチャ変換
	converter.ConvertTextureWICToDDS(argv[kFilePath]);

	CoUninitialize();
	system("pause");

	return 0;
}