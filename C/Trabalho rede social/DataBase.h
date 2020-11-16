/**
* @file   DataBase.h
* @brief  Arquivo com as assinaturas das funções de
*                saves dos dados do software.
* @author <Erik Neves>
* @date   2020-11-14
*/
#pragma once
#include "constantes.h"
#include "structs.h"

#ifndef __DataSave_h__
#define __DataSave_h__

Error LoadAllSavedData(HashTable * table);
Error SaveAllData(HashTable * table);

#endif /* __DataSave_h__ */