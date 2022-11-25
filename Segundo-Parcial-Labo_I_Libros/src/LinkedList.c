#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;

    this = (LinkedList*) malloc(sizeof(LinkedList));

    if(this != NULL)
    {
    	this->pFirstNode = NULL; //primer nodo apunto a NULL
    	this->size = 0; //Inicializo el tamaño en 0
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = this->size; //retorno el tamaño
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* node = NULL;

	if(this !=NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
	{
		node = this->pFirstNode;

		for(int i=0; i<nodeIndex; i++)//RECORRO HATA QUE SEA MENOS A NODEINDEX
		{
			node = node->pNextNode; //APUNTO AL SIGUIENTE NODO
		}
	}

    return node;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* newNode;
    Node* previusNode;

    if( this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this) )
    {
		newNode = (Node*) malloc(sizeof(Node));//creo un nodo

		if(newNode != NULL)
		{
			newNode->pElement = pElement; //asigno el puntero al elemento al nuevo nodo
			newNode->pNextNode = NULL; //el siguiente nodo apunto a NULL

			if(nodeIndex == 0)// si es el primer nodo
			{
				newNode->pNextNode = this->pFirstNode; // nuevo NODO apunta al Viejo 0
				this->pFirstNode = newNode; // Engancho la lista nodo ya que es el NUEVO 0
			}
			else
			{
				previusNode = getNode(this, nodeIndex - 1); //Consigo el NODO anterior
				newNode->pNextNode = previusNode->pNextNode; //el nuevo nodo apunta a lo que apuntaba el nodo que tengo atras
				previusNode->pNextNode = newNode;//el nodo que tengo atras apunta al nodo nuevo
			}
			this->size++;
			returnAux = 0;
		}
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
	int returnAux = -1;

	if( this != NULL )
	{
		returnAux = addNode(this, ll_len(this), pElement);
	}
	return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
	void* returnAux = NULL;
	Node* node = getNode(this, index);

	if( node != NULL )
	{
		returnAux = node->pElement; //retorno el puntero al enlemento
	}

	return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* node = getNode(this, index);

	if( node != NULL )
	{
		node->pElement = pElement;
		returnAux = 0;
	}

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* nodeRemove = getNode(this, index);

	if( nodeRemove != NULL )
	{
		if( index == 0 )
		{
			this->pFirstNode = nodeRemove->pNextNode;
			free(nodeRemove);
			this->size--;
			returnAux = 0;
		}

		Node* previusNode = getNode(this, index-1);

		if( previusNode != NULL )
		{
			previusNode->pNextNode = nodeRemove->pNextNode;
			free(nodeRemove);
			this->size--;
			returnAux = 0;
		}
	}

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int len,i;

	len = ll_len(this);

	if( this != NULL )
	{
		for( i = 0; i < len; i++ )
		{
			ll_remove(this, i);
		}
		returnAux = 0;
	}

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if( this != NULL )
	{
    	if( !ll_clear(this) )
		{
			free(this);
			returnAux = 0;
		}
	}

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i,len;

	len = ll_len(this);

	if( this != NULL )
	{
		for( i = 0; i < len; i++ )
		{
			Node* node = getNode(this, i);
			if( node != NULL && pElement == node->pElement )
			{
				returnAux = i;
				break;//para que me devuelva la primer ocurrencia
			}
		}
	}

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if(	this != NULL )
	{
		returnAux = 0;

		if( !ll_len(this) ) // si la lista esta vacia
		{
			returnAux = 1;
		}
	}
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    if( this != NULL )
	{
		returnAux = addNode(this, index, pElement);
	}
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    int len = ll_len(this);

	   if( this != NULL && index >= 0 && index < len )
	   {
		   //el elemento pude ser Null, por eso no l verifico
			returnAux = ll_get(this, index);

			if( ll_remove(this, index) == -1 )
			{
				returnAux = NULL;
			}
	   }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int index;

    if( this != NULL )
    {
    	returnAux = 0;
    	//busco en que index esta el pElement
    	index = ll_indexOf(this, pElement);

    	//obtengo el pElement
    	void* element = ll_get(this, index);

    	if( index != -1 && pElement == element )
    	{
    		returnAux = 1;
    	}
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    if( this != NULL && this2 != NULL )
	{
		returnAux = 1;

		for( int i = 0 ; i < ll_len(this2); i++ )
		{
			// !ll_contains(this, ll_get(this2, i))
			// ==
			if( ll_contains(this, ll_get(this2, i)) == 0)//obtengo los punteros elemntos
			{
				returnAux = 0;
				break;
			}
		}
	}
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;

    if( this != NULL && from >= 0 && from <= ll_len(this) && to > from && to <= ll_len(this) )
    {
    	cloneArray = ll_newLinkedList();

    	if( cloneArray != NULL )
    	{
    		for(int i = 0 ; i < to ;i++ )
    		{
    			void* element = ll_get(this, i);

    			if(ll_add(cloneArray, element) == -1)
    			{
    				cloneArray = NULL;
    			}
    		}
    	}
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    if( this != NULL )
	{
		cloneArray = ll_subList(this, 0, ll_len(this));
	}
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int i,j;
    int len = ll_len(this);
	void* auxElement;

	if(this != NULL && pFunc != NULL && order >= 0 && order <= 1)
	{
		for(i = 0; i < len-1; i++)
		{
			for(j = i+1; j<len ;j++)
			{
				if( (order == 1 && pFunc( ll_get(this, i), ll_get(this, j) )> 0) || (order == 0 && pFunc( ll_get(this, i), ll_get(this, j) )< 0) )
				{
					auxElement = ll_get(this, i);
					ll_set(this, i, ll_get(this, j));
					ll_set(this, j, auxElement);
				}
			}
		}
		returnAux = 0;
	}
    return returnAux;
}


//recibe la lista y la funcion con su element
int ll_map( LinkedList* this, int (*pFunc)(void*) )
{
    int returnAux = -1;
    void* pElement = NULL;
    int tam = ll_len(this);
    int i;

    if(this != NULL && pFunc != NULL)
    {
        for(i = 0; i < tam; i++)//recorro la lista
        {
            pElement = ll_get(this, i);//obtengo x indice en cada iteracion

            if(pElement != NULL)
            {
                pFunc(pElement); //paso por referencia el pElelento a la funcion

                returnAux = 0;
            }
        }
    }
    return returnAux;
}


LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*))
{
    LinkedList* listaFiltrada = NULL;
    void* auxElement = NULL;

    if(this != NULL && pFunc!= NULL)
    {
        listaFiltrada = ll_newLinkedList();//creo una lista
        if(listaFiltrada != NULL)
        {
            for(int i=0; i<ll_len(this); i++) //recorro la lista
            {
                auxElement = ll_get(this, i); //obtengo el puntero al elemento
                if(pFunc(auxElement) == 1)//si la funcion retorna 1
                {
                    ll_add(listaFiltrada, auxElement);//agrego el elemento a la lista
                }
            }
        }
    }

    return listaFiltrada; //retorno la lista con el elemento agregado
}
