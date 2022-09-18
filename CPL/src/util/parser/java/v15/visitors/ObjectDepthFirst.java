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

package util.parser.java.v15.visitors;
import util.parser.java.v15.nodes.*;
import java.util.*;

/**
 * Provides default methods which visit each node in the tree in depth-first
 * order.  Your visitors may extend this class.
 */
public class ObjectDepthFirst implements ObjectVisitor {
   //
   // Auto class visitors--probably don't need to be overridden.
   //
   public Object visit(NodeList n, Object argu) {
      Object _ret=null;
      for ( Enumeration<?> e = n.elements(); e.hasMoreElements(); ) {
         ((Node)e.nextElement()).accept(this,argu);
      }
      return _ret;
   }

   public Object visit(NodeListOptional n, Object argu) {
      if ( n.present() ) {
         Object _ret=null;
         for ( Enumeration<?> e = n.elements(); e.hasMoreElements(); ) {
            ((Node)e.nextElement()).accept(this,argu);
         }
         return _ret;
      }
      else
         return null;
   }

   public Object visit(NodeOptional n, Object argu) {
      if ( n.present() )
         return n.node.accept(this,argu);
      else
         return null;
   }

   public Object visit(NodeSequence n, Object argu) {
      Object _ret=null;
      for ( Enumeration<?> e = n.elements(); e.hasMoreElements(); ) {
         ((Node)e.nextElement()).accept(this,argu);
      }
      return _ret;
   }

   public Object visit(NodeToken n, Object argu) { return null; }

   //
   // User-generated visitor methods below
   //

   /**
    * f0 -> [ PackageDeclaration() ]
    * f1 -> ( ImportDeclaration() )*
    * f2 -> ( TypeDeclaration() )*
    * f3 -> ( <"\u001a"> )?
    * f4 -> ( <STUFF_TO_IGNORE: ~[]> )?
    * f5 -> <EOF>
    */
   public Object visit(CompilationUnit n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      n.f3.accept(this, argu);
      n.f4.accept(this, argu);
      n.f5.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> Modifiers()
    * f1 -> "package"
    * f2 -> Name()
    * f3 -> ";"
    */
   public Object visit(PackageDeclaration n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      n.f3.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "import"
    * f1 -> [ "static" ]
    * f2 -> Name()
    * f3 -> [ "." "*" ]
    * f4 -> ";"
    */
   public Object visit(ImportDeclaration n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      n.f3.accept(this, argu);
      n.f4.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> ( ( "public" | "static" | "protected" | "private" | "final" | "abstract" | "synchronized" | "native" | "transient" | "volatile" | "strictfp" | Annotation() ) )*
    */
   public Object visit(Modifiers n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> ";"
    *       | Modifiers() ( ClassOrInterfaceDeclaration() | EnumDeclaration() | AnnotationTypeDeclaration() )
    */
   public Object visit(TypeDeclaration n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> ( "class" | "interface" )
    * f1 -> <IDENTIFIER>
    * f2 -> [ TypeParameters() ]
    * f3 -> [ ExtendsList() ]
    * f4 -> [ ImplementsList() ]
    * f5 -> ClassOrInterfaceBody()
    */
   public Object visit(ClassOrInterfaceDeclaration n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      n.f3.accept(this, argu);
      n.f4.accept(this, argu);
      n.f5.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "extends"
    * f1 -> ClassOrInterfaceType()
    * f2 -> ( "," ClassOrInterfaceType() )*
    */
   public Object visit(ExtendsList n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "implements"
    * f1 -> ClassOrInterfaceType()
    * f2 -> ( "," ClassOrInterfaceType() )*
    */
   public Object visit(ImplementsList n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "enum"
    * f1 -> <IDENTIFIER>
    * f2 -> [ ImplementsList(false) ]
    * f3 -> EnumBody()
    */
   public Object visit(EnumDeclaration n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      n.f3.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "{"
    * f1 -> [ EnumConstant() ( "," EnumConstant() )* ]
    * f2 -> [ "," ]
    * f3 -> [ ";" ( ClassOrInterfaceBodyDeclaration(false) )* ]
    * f4 -> "}"
    */
   public Object visit(EnumBody n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      n.f3.accept(this, argu);
      n.f4.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> Modifiers()
    * f1 -> <IDENTIFIER>
    * f2 -> [ Arguments() ]
    * f3 -> [ ClassOrInterfaceBody(false) ]
    */
   public Object visit(EnumConstant n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      n.f3.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "<"
    * f1 -> TypeParameter()
    * f2 -> ( "," TypeParameter() )*
    * f3 -> ">"
    */
   public Object visit(TypeParameters n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      n.f3.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> <IDENTIFIER>
    * f1 -> [ TypeBound() ]
    */
   public Object visit(TypeParameter n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "extends"
    * f1 -> ClassOrInterfaceType()
    * f2 -> ( "&" ClassOrInterfaceType() )*
    */
   public Object visit(TypeBound n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "{"
    * f1 -> ( ClassOrInterfaceBodyDeclaration() )*
    * f2 -> "}"
    */
   public Object visit(ClassOrInterfaceBody n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> Initializer()
    *       | Modifiers() ( ClassOrInterfaceDeclaration() | EnumDeclaration() | ConstructorDeclaration() | FieldDeclaration() | MethodDeclaration() )
    *       | ";"
    */
   public Object visit(ClassOrInterfaceBodyDeclaration n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> Type()
    * f1 -> VariableDeclarator()
    * f2 -> ( "," VariableDeclarator() )*
    * f3 -> ";"
    */
   public Object visit(FieldDeclaration n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      n.f3.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> VariableDeclaratorId()
    * f1 -> [ "=" VariableInitializer() ]
    */
   public Object visit(VariableDeclarator n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> <IDENTIFIER>
    * f1 -> ( "[" "]" )*
    */
   public Object visit(VariableDeclaratorId n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> ArrayInitializer()
    *       | Expression()
    */
   public Object visit(VariableInitializer n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "{"
    * f1 -> [ VariableInitializer() ( "," VariableInitializer() )* ]
    * f2 -> [ "," ]
    * f3 -> "}"
    */
   public Object visit(ArrayInitializer n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      n.f3.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> [ TypeParameters() ]
    * f1 -> ResultType()
    * f2 -> MethodDeclarator()
    * f3 -> [ "throws" NameList() ]
    * f4 -> ( Block() | ";" )
    */
   public Object visit(MethodDeclaration n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      n.f3.accept(this, argu);
      n.f4.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> <IDENTIFIER>
    * f1 -> FormalParameters()
    * f2 -> ( "[" "]" )*
    */
   public Object visit(MethodDeclarator n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "("
    * f1 -> [ FormalParameter() ( "," FormalParameter() )* ]
    * f2 -> ")"
    */
   public Object visit(FormalParameters n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> Modifiers()
    * f1 -> Type()
    * f2 -> [ "..." ]
    * f3 -> VariableDeclaratorId()
    */
   public Object visit(FormalParameter n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      n.f3.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> [ TypeParameters() ]
    * f1 -> <IDENTIFIER>
    * f2 -> FormalParameters()
    * f3 -> [ "throws" NameList() ]
    * f4 -> "{"
    * f5 -> [ ExplicitConstructorInvocation() ]
    * f6 -> ( BlockStatement() )*
    * f7 -> "}"
    */
   public Object visit(ConstructorDeclaration n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      n.f3.accept(this, argu);
      n.f4.accept(this, argu);
      n.f5.accept(this, argu);
      n.f6.accept(this, argu);
      n.f7.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> ( <IDENTIFIER> "." )*
    * f1 -> [ "this" "." ]
    * f2 -> [ TypeArguments() ]
    * f3 -> ( "this" | "super" )
    * f4 -> Arguments()
    * f5 -> ";"
    */
   public Object visit(ExplicitConstructorInvocation n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      n.f3.accept(this, argu);
      n.f4.accept(this, argu);
      n.f5.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> [ "static" ]
    * f1 -> Block()
    */
   public Object visit(Initializer n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> ReferenceType()
    *       | PrimitiveType()
    */
   public Object visit(Type n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> PrimitiveType() ( "[" "]" )+
    *       | ClassOrInterfaceType() ( "[" "]" )*
    */
   public Object visit(ReferenceType n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> <IDENTIFIER>
    * f1 -> [ TypeArguments() ]
    * f2 -> ( "." <IDENTIFIER> [ TypeArguments() ] )*
    */
   public Object visit(ClassOrInterfaceType n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "<"
    * f1 -> TypeArgument()
    * f2 -> ( "," TypeArgument() )*
    * f3 -> ">"
    */
   public Object visit(TypeArguments n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      n.f3.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> ReferenceType()
    *       | "?" [ WildcardBounds() ]
    */
   public Object visit(TypeArgument n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "extends" ReferenceType()
    *       | "super" ReferenceType()
    */
   public Object visit(WildcardBounds n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "boolean"
    *       | "char"
    *       | "byte"
    *       | "short"
    *       | "int"
    *       | "long"
    *       | "float"
    *       | "double"
    */
   public Object visit(PrimitiveType n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "void"
    *       | Type()
    */
   public Object visit(ResultType n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> <IDENTIFIER>
    * f1 -> ( "." <IDENTIFIER> )*
    */
   public Object visit(Name n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> Name()
    * f1 -> ( "," Name() )*
    */
   public Object visit(NameList n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> ConditionalExpression()
    * f1 -> [ AssignmentOperator() Expression() ]
    */
   public Object visit(Expression n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "="
    *       | "*="
    *       | "/="
    *       | "%="
    *       | "+="
    *       | "-="
    *       | "<<="
    *       | ">>="
    *       | ">>>="
    *       | "&="
    *       | "^="
    *       | "|="
    */
   public Object visit(AssignmentOperator n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> ConditionalOrExpression()
    * f1 -> [ "?" Expression() ":" Expression() ]
    */
   public Object visit(ConditionalExpression n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> ConditionalAndExpression()
    * f1 -> ( "||" ConditionalAndExpression() )*
    */
   public Object visit(ConditionalOrExpression n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> InclusiveOrExpression()
    * f1 -> ( "&&" InclusiveOrExpression() )*
    */
   public Object visit(ConditionalAndExpression n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> ExclusiveOrExpression()
    * f1 -> ( "|" ExclusiveOrExpression() )*
    */
   public Object visit(InclusiveOrExpression n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> AndExpression()
    * f1 -> ( "^" AndExpression() )*
    */
   public Object visit(ExclusiveOrExpression n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> EqualityExpression()
    * f1 -> ( "&" EqualityExpression() )*
    */
   public Object visit(AndExpression n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> InstanceOfExpression()
    * f1 -> ( ( "==" | "!=" ) InstanceOfExpression() )*
    */
   public Object visit(EqualityExpression n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> RelationalExpression()
    * f1 -> [ "instanceof" Type() ]
    */
   public Object visit(InstanceOfExpression n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> ShiftExpression()
    * f1 -> ( ( "<" | ">" | "<=" | ">=" ) ShiftExpression() )*
    */
   public Object visit(RelationalExpression n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> AdditiveExpression()
    * f1 -> ( ( "<<" | RSIGNEDSHIFT() | RUNSIGNEDSHIFT() ) AdditiveExpression() )*
    */
   public Object visit(ShiftExpression n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> MultiplicativeExpression()
    * f1 -> ( ( "+" | "-" ) MultiplicativeExpression() )*
    */
   public Object visit(AdditiveExpression n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> UnaryExpression()
    * f1 -> ( ( "*" | "/" | "%" ) UnaryExpression() )*
    */
   public Object visit(MultiplicativeExpression n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> ( "+" | "-" ) UnaryExpression()
    *       | PreIncrementExpression()
    *       | PreDecrementExpression()
    *       | UnaryExpressionNotPlusMinus()
    */
   public Object visit(UnaryExpression n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "++"
    * f1 -> PrimaryExpression()
    */
   public Object visit(PreIncrementExpression n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "--"
    * f1 -> PrimaryExpression()
    */
   public Object visit(PreDecrementExpression n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> ( "~" | "!" ) UnaryExpression()
    *       | CastExpression()
    *       | PostfixExpression()
    */
   public Object visit(UnaryExpressionNotPlusMinus n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "(" PrimitiveType()
    *       | "(" Type() "[" "]"
    *       | "(" Type() ")" ( "~" | "!" | "(" | <IDENTIFIER> | "this" | "super" | "new" | Literal() )
    */
   public Object visit(CastLookahead n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> PrimaryExpression()
    * f1 -> [ "++" | "--" ]
    */
   public Object visit(PostfixExpression n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "(" Type() ")" UnaryExpression()
    *       | "(" Type() ")" UnaryExpressionNotPlusMinus()
    */
   public Object visit(CastExpression n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> PrimaryPrefix()
    * f1 -> ( PrimarySuffix() )*
    */
   public Object visit(PrimaryExpression n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "."
    * f1 -> TypeArguments()
    * f2 -> <IDENTIFIER>
    */
   public Object visit(MemberSelector n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> Literal()
    *       | ( <IDENTIFIER> "." )* "this"
    *       | "super" "." <IDENTIFIER>
    *       | "(" Expression() ")"
    *       | AllocationExpression()
    *       | ResultType() "." "class"
    *       | Name()
    */
   public Object visit(PrimaryPrefix n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "." "super"
    *       | "." "this"
    *       | "." AllocationExpression()
    *       | MemberSelector()
    *       | "[" Expression() "]"
    *       | "." <IDENTIFIER>
    *       | Arguments()
    */
   public Object visit(PrimarySuffix n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> <INTEGER_LITERAL>
    *       | <FLOATING_POINT_LITERAL>
    *       | <CHARACTER_LITERAL>
    *       | <STRING_LITERAL>
    *       | BooleanLiteral()
    *       | NullLiteral()
    */
   public Object visit(Literal n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "true"
    *       | "false"
    */
   public Object visit(BooleanLiteral n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "null"
    */
   public Object visit(NullLiteral n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "("
    * f1 -> [ ArgumentList() ]
    * f2 -> ")"
    */
   public Object visit(Arguments n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> Expression()
    * f1 -> ( "," Expression() )*
    */
   public Object visit(ArgumentList n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "new" PrimitiveType() ArrayDimsAndInits()
    *       | "new" ClassOrInterfaceType() [ TypeArguments() ] ( ArrayDimsAndInits() | Arguments() [ ClassOrInterfaceBody(false) ] )
    */
   public Object visit(AllocationExpression n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> ( "[" Expression() "]" )+ ( "[" "]" )*
    *       | ( "[" "]" )+ ArrayInitializer()
    */
   public Object visit(ArrayDimsAndInits n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> LabeledStatement()
    *       | AssertStatement()
    *       | Block()
    *       | EmptyStatement()
    *       | StatementExpression() ";"
    *       | SwitchStatement()
    *       | IfStatement()
    *       | WhileStatement()
    *       | DoStatement()
    *       | ForStatement()
    *       | BreakStatement()
    *       | ContinueStatement()
    *       | ReturnStatement()
    *       | ThrowStatement()
    *       | SynchronizedStatement()
    *       | TryStatement()
    */
   public Object visit(Statement n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "assert"
    * f1 -> Expression()
    * f2 -> [ ":" Expression() ]
    * f3 -> ";"
    */
   public Object visit(AssertStatement n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      n.f3.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> <IDENTIFIER>
    * f1 -> ":"
    * f2 -> Statement()
    */
   public Object visit(LabeledStatement n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "{"
    * f1 -> ( BlockStatement() )*
    * f2 -> "}"
    */
   public Object visit(Block n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> LocalVariableDeclaration() ";"
    *       | Statement()
    *       | ClassOrInterfaceDeclaration(0)
    */
   public Object visit(BlockStatement n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> Modifiers()
    * f1 -> Type()
    * f2 -> VariableDeclarator()
    * f3 -> ( "," VariableDeclarator() )*
    */
   public Object visit(LocalVariableDeclaration n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      n.f3.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> ";"
    */
   public Object visit(EmptyStatement n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> PreIncrementExpression()
    *       | PreDecrementExpression()
    *       | PrimaryExpression() [ "++" | "--" | AssignmentOperator() Expression() ]
    */
   public Object visit(StatementExpression n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "switch"
    * f1 -> "("
    * f2 -> Expression()
    * f3 -> ")"
    * f4 -> "{"
    * f5 -> ( SwitchLabel() ( BlockStatement() )* )*
    * f6 -> "}"
    */
   public Object visit(SwitchStatement n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      n.f3.accept(this, argu);
      n.f4.accept(this, argu);
      n.f5.accept(this, argu);
      n.f6.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "case" Expression() ":"
    *       | "default" ":"
    */
   public Object visit(SwitchLabel n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "if"
    * f1 -> "("
    * f2 -> Expression()
    * f3 -> ")"
    * f4 -> Statement()
    * f5 -> [ "else" Statement() ]
    */
   public Object visit(IfStatement n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      n.f3.accept(this, argu);
      n.f4.accept(this, argu);
      n.f5.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "while"
    * f1 -> "("
    * f2 -> Expression()
    * f3 -> ")"
    * f4 -> Statement()
    */
   public Object visit(WhileStatement n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      n.f3.accept(this, argu);
      n.f4.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "do"
    * f1 -> Statement()
    * f2 -> "while"
    * f3 -> "("
    * f4 -> Expression()
    * f5 -> ")"
    * f6 -> ";"
    */
   public Object visit(DoStatement n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      n.f3.accept(this, argu);
      n.f4.accept(this, argu);
      n.f5.accept(this, argu);
      n.f6.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "for"
    * f1 -> "("
    * f2 -> ( Modifiers() Type() <IDENTIFIER> ":" Expression() | [ ForInit() ] ";" [ Expression() ] ";" [ ForUpdate() ] )
    * f3 -> ")"
    * f4 -> Statement()
    */
   public Object visit(ForStatement n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      n.f3.accept(this, argu);
      n.f4.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> LocalVariableDeclaration()
    *       | StatementExpressionList()
    */
   public Object visit(ForInit n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> StatementExpression()
    * f1 -> ( "," StatementExpression() )*
    */
   public Object visit(StatementExpressionList n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> StatementExpressionList()
    */
   public Object visit(ForUpdate n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "break"
    * f1 -> [ <IDENTIFIER> ]
    * f2 -> ";"
    */
   public Object visit(BreakStatement n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "continue"
    * f1 -> [ <IDENTIFIER> ]
    * f2 -> ";"
    */
   public Object visit(ContinueStatement n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "return"
    * f1 -> [ Expression() ]
    * f2 -> ";"
    */
   public Object visit(ReturnStatement n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "throw"
    * f1 -> Expression()
    * f2 -> ";"
    */
   public Object visit(ThrowStatement n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "synchronized"
    * f1 -> "("
    * f2 -> Expression()
    * f3 -> ")"
    * f4 -> Block()
    */
   public Object visit(SynchronizedStatement n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      n.f3.accept(this, argu);
      n.f4.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "try"
    * f1 -> Block()
    * f2 -> ( "catch" "(" FormalParameter() ")" Block() )*
    * f3 -> [ "finally" Block() ]
    */
   public Object visit(TryStatement n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      n.f3.accept(this, argu);
      return _ret;
   }

   /**
">"
    * f0 -> ">"
    * f1 -> ">"
    */
   public Object visit(RUNSIGNEDSHIFT n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      return _ret;
   }

   /**
">"
    * f0 -> ">"
    */
   public Object visit(RSIGNEDSHIFT n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> NormalAnnotation()
    *       | SingleMemberAnnotation()
    *       | MarkerAnnotation()
    */
   public Object visit(Annotation n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "@"
    * f1 -> Name()
    * f2 -> "("
    * f3 -> [ MemberValuePairs() ]
    * f4 -> ")"
    */
   public Object visit(NormalAnnotation n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      n.f3.accept(this, argu);
      n.f4.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "@"
    * f1 -> Name()
    */
   public Object visit(MarkerAnnotation n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "@"
    * f1 -> Name()
    * f2 -> "("
    * f3 -> MemberValue()
    * f4 -> ")"
    */
   public Object visit(SingleMemberAnnotation n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      n.f3.accept(this, argu);
      n.f4.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> MemberValuePair()
    * f1 -> ( "," MemberValuePair() )*
    */
   public Object visit(MemberValuePairs n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> <IDENTIFIER>
    * f1 -> "="
    * f2 -> MemberValue()
    */
   public Object visit(MemberValuePair n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> Annotation()
    *       | MemberValueArrayInitializer()
    *       | ConditionalExpression()
    */
   public Object visit(MemberValue n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "{"
    * f1 -> MemberValue()
    * f2 -> ( "," MemberValue() )*
    * f3 -> [ "," ]
    * f4 -> "}"
    */
   public Object visit(MemberValueArrayInitializer n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      n.f3.accept(this, argu);
      n.f4.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "@"
    * f1 -> "interface"
    * f2 -> <IDENTIFIER>
    * f3 -> AnnotationTypeBody()
    */
   public Object visit(AnnotationTypeDeclaration n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      n.f3.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "{"
    * f1 -> ( AnnotationTypeMemberDeclaration() )*
    * f2 -> "}"
    */
   public Object visit(AnnotationTypeBody n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> Modifiers() ( Type() <IDENTIFIER> "(" ")" [ DefaultValue() ] ";" | ClassOrInterfaceDeclaration() | EnumDeclaration() | AnnotationTypeDeclaration() | FieldDeclaration() )
    *       | ";"
    */
   public Object visit(AnnotationTypeMemberDeclaration n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "default"
    * f1 -> MemberValue()
    */
   public Object visit(DefaultValue n, Object argu) {
      Object _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      return _ret;
   }

}
