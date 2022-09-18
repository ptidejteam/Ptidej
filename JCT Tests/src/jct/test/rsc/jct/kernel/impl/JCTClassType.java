/**
 * @author Mathieu Lemoine
 * @created 2009-01-08 (木)
 *
 * Licensed under 3-clause BSD License:
 * Copyright © 2009, Mathieu Lemoine
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *  * Neither the name of Mathieu Lemoine nor the
 *    names of contributors may be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY Mathieu Lemoine ''AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL Mathieu Lemoine BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

package jct.test.rsc.jct.kernel.impl;


import java.util.Set;
import java.util.HashSet;
import java.util.Collections;

import java.io.Writer;
import java.io.IOException;


import jct.test.rsc.jct.kernel.Constants;
import jct.test.rsc.jct.kernel.IJCTClass;
import jct.test.rsc.jct.kernel.IJCTClassType;
import jct.test.rsc.jct.kernel.IJCTNonPrimitiveType;
import jct.test.rsc.jct.kernel.IJCTRootNode;
import jct.test.rsc.jct.kernel.IJCTSelector;
import jct.test.rsc.jct.kernel.IJCTVisitor;
import jct.test.rsc.jct.kernel.JCTKind;
import jct.test.rsc.jct.util.reference.NotNullableReference;


/**
 * This class represents a Class Type.<br>
 * All methods but {@link #getSelector} and {@link #setSelector},
 * may throw NullPointerException if the element is unresolved.
 * <br><br>
 * TODO : separate class and interface
 * 
 * Default implementation for {@link jct.test.rsc.jct.kernel.IJCTClassType}
 *
 * @author Mathieu Lemoine
 */
class JCTClassType extends JCTNonPrimitiveType<IJCTSelector<IJCTClass>> implements IJCTClassType
{
    /**
     * class declaration of this class type
     */
    private final NotNullableReference<IJCTSelector<IJCTClass>> classDeclaration;
    
    
    JCTClassType(final IJCTRootNode aRootNode, final IJCTSelector<IJCTClass> classDeclaration)
    {
        super(aRootNode);
        if(aRootNode instanceof JCTRootNode)
            ((JCTRootNode)aRootNode).registerClassType(this);
        this.classDeclaration = this.createInternalReference(classDeclaration);
        super.backpatchElements(this.classDeclaration);
    }
    
    /**
     * Returns the declared class represented by this type
     *
     * @return null iff the element is unresolved
     */
    @Override
	public IJCTSelector<IJCTClass> getSelector()
    {
        return this.classDeclaration.get();
    }
    
    /**
     * Modifies the declared class represented by this type.
     *
     * @throws IllegalStateException unless the element was previously not resolved
     */
    @Override
	public void setSelector(final IJCTSelector<IJCTClass> classSelector)
    {
        if(null != this.getSelector().getElement())
        throw new IllegalStateException("Can not change the selector unless it was previously erroneous");
        
        this.classDeclaration.set(classSelector);
    }
    
    /**
     * Returns the set of directly extended classes and directly implemented interfaces
     */
    @Override
	public Set<IJCTNonPrimitiveType> getDirectSuperClasses()
    {
        final IJCTClass clazz = this.getSelector().getElement();
        final Set<IJCTNonPrimitiveType> result = new HashSet<IJCTNonPrimitiveType>();
        
        final IJCTClassType extended = clazz.getDirectSuperClass();
        if(null != extended
           && this.getSelector().getElement() != extended.getSelector().getElement())
            result.add(extended);
        
        for(final IJCTClassType implemented : clazz.getDirectlyImplementedInterfaces())
            result.add(implemented);
        
        return Collections.unmodifiableSet(result);
    }
    
    /**
     * Returns the kind of this constituent (JCTKind.CLASS_TYPE)
     */
    @Override
	public JCTKind getKind()
    {
        return JCTKind.CLASS_TYPE;
    }
    
    /**
     * Calls the appropriate visit* method on the visitor
     */
    @Override
	public <R, P> R accept(final IJCTVisitor<R, P> visitor, final P aP)
    {
        return visitor.visitClassType(this, aP);
    }
    
    @Override
	public String getTypeName()
    {
        JCTPathPart p = (JCTPath)this.getSelector().getElement().getPath();
    
        while(p.getResultKind() != JCTKind.CLASS)
            p = p.getNextPart();
    
        final StringBuilder str = new StringBuilder(Constants.CLASS_MARKER)
            .append(p.getData())
            .append(Constants.DOT_SEPARATOR);
        
        while(null != (p = p.getNextPart()))
            str.append(p.getData()).append(Constants.DOLLAR_SEPARATOR);
    
        return str.substring(0, str.length() - 1);
    }
    
    @Override
	public Writer getSourceCode(final Writer aWriter) throws IOException
    { return this.getSelector().getSourceCode(aWriter); }
    
    @Override
    public boolean equals(final Object o)
    {
        return o instanceof IJCTClassType
            && this.getSelector().equals(((IJCTClassType)o).getSelector());
    }
    
    @Override
    public void setName(final String newName)
    { throw new UnsupportedOperationException("A ClassType has a (computed and not settable) type name, but no name, therefore you can not set it !"); }
    
    @Override
    public String getName()
    { return this.getTypeName(); }

}
