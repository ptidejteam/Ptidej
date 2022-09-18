/*
 * The Apache Software License, Version 1.1
 *
 *
 * Copyright (c) 1999 The Apache Software Foundation.  All rights 
 * reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer. 
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * 3. The end-user documentation included with the redistribution,
 *    if any, must include the following acknowledgment:  
 *       "This product includes software developed by the
 *        Apache Software Foundation (http://www.apache.org/)."
 *    Alternately, this acknowledgment may appear in the software itself,
 *    if and wherever such third-party acknowledgments normally appear.
 *
 * 4. The names "Xerces" and "Apache Software Foundation" must
 *    not be used to endorse or promote products derived from this
 *    software without prior written permission. For written 
 *    permission, please contact apache@apache.org.
 *
 * 5. Products derived from this software may not be called "Apache",
 *    nor may "Apache" appear in their name, without prior written
 *    permission of the Apache Software Foundation.
 *
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESSED OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED.  IN NO EVENT SHALL THE APACHE SOFTWARE FOUNDATION OR
 * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
 * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 * ====================================================================
 *
 * This software consists of voluntary contributions made by many
 * individuals on behalf of the Apache Software Foundation and was
 * originally based on software copyright (c) 1999, International
 * Business Machines, Inc., http://www.apache.org.  For more
 * information on the Apache Software Foundation, please see
 * <http://www.apache.org/>.
 */

package org.apache.xerces.validators.dtd;

import org.apache.xerces.framework.XMLContentSpecNode;
import org.apache.xerces.utils.StringPool;
import org.apache.xerces.utils.ImplementationMessages;

/**
 *
 * @version
 */
public class CMLeaf extends CMNode
{
    // -------------------------------------------------------------------
    //  Constructors
    // -------------------------------------------------------------------
    public CMLeaf(int type, int elementIndex, int position) throws CMException
    {
        super(type);

        // Insure that its one of the types we require
        if (type() != XMLContentSpecNode.CONTENTSPECNODE_LEAF)
            throw new CMException(ImplementationMessages.VAL_LST);

        // Store the element index and position
        fElementIndex = elementIndex;
        fPosition = position;
    }

    public CMLeaf(int type, int elementIndex) throws CMException
    {
        super(type);

        // Insure that its one of the types we require
        if (type() != XMLContentSpecNode.CONTENTSPECNODE_LEAF)
            throw new CMException(ImplementationMessages.VAL_LST);

        // Store the element index and position
        fElementIndex = elementIndex;
    }


    // -------------------------------------------------------------------
    //  Package final methods
    // -------------------------------------------------------------------
    final int getElemIndex()
    {
        return fElementIndex;
    }

    final int getPosition()
    {
        return fPosition;
    }

    final void setPosition(int newPosition)
    {
        fPosition = newPosition;
    }


    // -------------------------------------------------------------------
    //  Package, inherited methods
    // -------------------------------------------------------------------
    boolean isNullable() throws CMException
    {
        // Leaf nodes are never nullable unless its an epsilon node
        return (fPosition == -1);
    }

    String toString(StringPool stringPool)
    {
        StringBuffer strRet = new StringBuffer(stringPool.toString(fElementIndex));

        if (fPosition >= 0)
        {
            strRet.append
            (
                " (Pos:"
                + Integer.valueOf(fPosition).toString()
                + ")"
            );
        }
        return strRet.toString();
    }


    // -------------------------------------------------------------------
    //  Protected, inherited methods
    // -------------------------------------------------------------------
    protected void calcFirstPos(CMStateSet toSet) throws CMException
    {
        // If we are an epsilon node, then the first pos is an empty set
        if (fPosition == -1)
            toSet.zeroBits();

        // Otherwise, its just the one bit of our position
        else
            toSet.setBit(fPosition);
    }

    protected void calcLastPos(CMStateSet toSet) throws CMException
    {
        // If we are an epsilon node, then the last pos is an empty set
        if (fPosition == -1)
            toSet.zeroBits();

        // Otherwise, its just the one bit of our position
        else
            toSet.setBit(fPosition);
    }


    // -------------------------------------------------------------------
    //  Private data members
    //
    //  fElementIndex
    //      This is the element decl pool index of the element that this
    //      leaf represents.
    //
    //  fPosition
    //      Part of the algorithm to convert a regex directly to a DFA
    //      numbers each leaf sequentially. If its -1, that means its an
    //      epsilon node. Zero and greater are non-epsilon positions.
    // -------------------------------------------------------------------
    private int fElementIndex   = 0;
    private int fPosition       = -1;
};
