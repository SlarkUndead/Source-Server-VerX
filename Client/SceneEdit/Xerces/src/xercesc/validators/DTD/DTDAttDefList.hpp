/*
 * Copyright 1999-2000,2004 The Apache Software Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *      http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * $Id: DTDAttDefList.hpp 191054 2005-06-17 02:56:35Z jberry $
 */


#if !defined(DTDATTDEFLIST_HPP)
#define DTDATTDEFLIST_HPP

#include <../../../SceneEdit/Xerces/src/xercesc/util/RefHashTableOf.hpp>
#include <xercesc/validators/DTD/DTDElementDecl.hpp>

XERCES_CPP_NAMESPACE_BEGIN

//
//  This is a derivative of the framework abstract class which defines the
//  interface to a list of attribute defs that belong to a particular
//  element. The scanner needs to be able to get a list of the attributes
//  that an element supports, for use during the validation process and for
//  fixed/default attribute processing.
//
//  Since each validator can store attributes differently, this abstract
//  interface allows each validator to provide an implementation of this
//  data strucure that works best for it.
//
//  For us, we just wrap the RefHashTableOf collection that the DTDElementDecl
//  class uses to store the attributes that belong to it.
//
//  This clss does not adopt the hash table, it just references it. The
//  hash table is owned by the element decl it is a member of.
//
class VALIDATORS_EXPORT DTDAttDefList : public XMLAttDefList
{
public :
    // -----------------------------------------------------------------------
    //  Constructors and Destructor
    // -----------------------------------------------------------------------
    DTDAttDefList
    (
        RefHashTableOf<DTDAttDef>* const    listToUse,
        MemoryManager* const manager = XMLPlatformUtils::fgMemoryManager
    );

    ~DTDAttDefList();


    // -----------------------------------------------------------------------
    //  Implementation of the virtual interface
    // -----------------------------------------------------------------------

    /** 
     * @deprecated This method is not thread-safe.
     */
    virtual bool hasMoreElements() const;
    virtual bool isEmpty() const;
    virtual XMLAttDef* findAttDef
    (
        const   unsigned long       uriID
        , const XMLCh* const        attName
    );
    virtual const XMLAttDef* findAttDef
    (
        const   unsigned long       uriID
        , const XMLCh* const        attName
    )   const;
    virtual XMLAttDef* findAttDef
    (
        const   XMLCh* const        attURI
        , const XMLCh* const        attName
    );
    virtual const XMLAttDef* findAttDef
    (
        const   XMLCh* const        attURI
        , const XMLCh* const        attName
    )   const;

    /** 
     * @deprecated This method is not thread-safe.
     */
    virtual XMLAttDef& nextElement();

    /** 
     * @deprecated This method is not thread-safe.
     */
    virtual void Reset();

    /**
     * return total number of attributes in this list
     */
    virtual unsigned int getAttDefCount() const ;

    /**
     * return attribute at the index-th position in the list.
     */
    virtual XMLAttDef &getAttDef(unsigned int index) ;

    /**
     * return attribute at the index-th position in the list.
     */
    virtual const XMLAttDef &getAttDef(unsigned int index) const ;

    /***
     * Support for Serialization/De-serialization
     ***/
    DECL_XSERIALIZABLE(DTDAttDefList)

	DTDAttDefList(MemoryManager* const manager = XMLPlatformUtils::fgMemoryManager);

private :

    void addAttDef(DTDAttDef *toAdd);
    // -----------------------------------------------------------------------
    // Unimplemented constructors and operators
    // -----------------------------------------------------------------------
    DTDAttDefList(const DTDAttDefList &);
    DTDAttDefList& operator = (const  DTDAttDefList&);

    // -----------------------------------------------------------------------
    //  Private data members
    //
    //  fEnum
    //      This is an enerator for the list that we use to do the enumerator
    //      type methods of this class.
    //
    //  fList
    //      The list of DTDAttDef objects that represent the attributes that
    //      a particular element supports.
    //  fArray
    //      vector of pointers to the DTDAttDef objects contained in this list
    //  fSize
    //      size of fArray
    //  fCount
    //      number of DTDAttDef objects currently stored in this list
    // -----------------------------------------------------------------------
    RefHashTableOfEnumerator<DTDAttDef>*    fEnum;
    RefHashTableOf<DTDAttDef>*              fList;
    DTDAttDef**                             fArray;
    unsigned int                            fSize;
    unsigned int                            fCount;

    friend class DTDElementDecl;
};

inline void DTDAttDefList::addAttDef(DTDAttDef *toAdd)
{
    if(fCount == fSize)
    {
        // need to grow fArray
        fSize <<= 1;
        DTDAttDef** newArray = (DTDAttDef **)((getMemoryManager())->allocate( sizeof(DTDAttDef*) * fSize ));
        memcpy(newArray, fArray, fCount * sizeof(DTDAttDef *));
        (getMemoryManager())->deallocate(fArray);
        fArray = newArray;
    }
    fArray[fCount++] = toAdd;
}

XERCES_CPP_NAMESPACE_END

#endif
