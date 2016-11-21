#pragma once

#include <Windows.h>
#include <time.h>
#include <string>
#include <vector>
#include <map>
#include <d3d9.h>
#include <d3dx9.h>
#include <tchar.h>
#include <Mmsystem.h>

#define SAFE_DELETE(p)       { if(p) { delete (p);     (p)=NULL; } }
#define SAFE_DELETE_ARRAY(p) { if(p) { [] (p);   (p)=NULL; } }
#define SAFE_RELEASE(p)      { if(p) { (p)->Release(); (p)=NULL; } }

#define GETSINGLE(classname)		classname::GetInstance()
#define Vector2 D3DXVECTOR2
#define Vector3 D3DXVECTOR3
#define Matrix D3DXMATRIX
#define Quaternion D3DXQUATERNION