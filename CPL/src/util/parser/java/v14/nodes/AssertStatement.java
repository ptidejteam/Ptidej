/*******************************************************************************
 * Copyright (c) 2014 Yann-Ga�l Gu�h�neuc and others.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the GNU Public License v2.0
 * which accompanies this distribution, and is available at
 * http://www.gnu.org/licenses/old-licenses/gpl-2.0.html
 * 
 * Contributors:
 *     Yann-Ga�l Gu�h�neuc and others, see in file; API and its implementation
 ******************************************************************************/
//
// Generated by JTB 1.2.2
//

package util.parser.java.v14.nodes;

/**
 * Grammar production:
 * f0 -> "assert"
 * f1 -> Expression()
 * f2 -> [ ":" Expression() ]
 * f3 -> ";"
 */
public class AssertStatement implements Node {
   /**
	 * 
	 */
	private static final long serialVersionUID = 1L;
public NodeToken f0;
   public Expression f1;
   public NodeOptional f2;
   public NodeToken f3;

   public AssertStatement(NodeToken n0, Expression n1, NodeOptional n2, NodeToken n3) {
      this.f0 = n0;
      this.f1 = n1;
      this.f2 = n2;
      this.f3 = n3;
   }

   public AssertStatement(Expression n0, NodeOptional n1) {
      this.f0 = new NodeToken("assert");
      this.f1 = n0;
      this.f2 = n1;
      this.f3 = new NodeToken(";");
   }

   public void accept(util.parser.java.v14.visitors.Visitor v) {
      v.visit(this);
   }
   public Object accept(util.parser.java.v14.visitors.ObjectVisitor v, Object argu) {
      return v.visit(this,argu);
   }
}

