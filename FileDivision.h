#pragma once
#ifndef __FILEDIVISION_H__
#define __FILEDIVISION_H__

void delete_enter(char *string);
// 문자열 속 개행문자(\n)가 있으면 개행문자를 NULL로 바꾸고, 없으면 입력버퍼를 개행문자까지 비움.

void delete_filename(char *string);
// 문자열 마지막 \ 다음부터 끝까지 제거.

void create_filename(char *path, char *filename, int number);
// path 문자열 마지막에 filename + number를 붙여넣음.
#endif
