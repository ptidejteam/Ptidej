/*
 * @(#)Test.java
 *
 * Project:		JHotdraw - a GUI framework for technical drawings
 *				http://www.jhotdraw.org
 *				http://jhotdraw.sourceforge.net
 * Copyright:	(c) by the original author(s) and all contributors
 * License:		Lesser GNU Public License (LGPL)
 *				http://www.opensource.org/licenses/lgpl-license.html
 */
package org.jhotdraw.test.figures;

// JUnitDoclet begin import
import org.jhotdraw.figures.BorderTool;
import org.jhotdraw.test.JHDTestCase;
// JUnitDoclet end import

/*
 * Generated by JUnitDoclet, a tool provided by
 * ObjectFab GmbH under LGPL.
 * Please see www.junitdoclet.org, www.gnu.org
 * and www.objectfab.de for informations about
 * the tool, the licence and the authors.
 */

// JUnitDoclet begin javadoc_class
/**
 * TestCase BorderToolTest is generated by
 * JUnitDoclet to hold the tests for BorderTool.
 * @see org.jhotdraw.figures.BorderTool
 */
// JUnitDoclet end javadoc_class
public class BorderToolTest
// JUnitDoclet begin extends_implements
extends JHDTestCase
// JUnitDoclet end extends_implements
{
	// JUnitDoclet begin class
	// instance variables, helper methods, ... put them in this marker
	private BorderTool bordertool;
	// JUnitDoclet end class

	/**
	 * Constructor BorderToolTest is
	 * basically calling the inherited constructor to
	 * initiate the TestCase for use by the Framework.
	 */
	public BorderToolTest(String name) {
		// JUnitDoclet begin method BorderToolTest
		super(name);
		// JUnitDoclet end method BorderToolTest
	}

	/**
	 * Factory method for instances of the class to be tested.
	 */
	public BorderTool createInstance() throws Exception {
		// JUnitDoclet begin method testcase.createInstance
		return new BorderTool(getDrawingEditor());
		// JUnitDoclet end method testcase.createInstance
	}

	/**
	 * Method setUp is overwriting the framework method to
	 * prepare an instance of this TestCase for a single test.
	 * It's called from the JUnit framework only.
	 */
	protected void setUp() throws Exception {
		// JUnitDoclet begin method testcase.setUp
		super.setUp();
		bordertool = createInstance();
		// JUnitDoclet end method testcase.setUp
	}

	/**
	 * Method tearDown is overwriting the framework method to
	 * clean up after each single test of this TestCase.
	 * It's called from the JUnit framework only.
	 */
	protected void tearDown() throws Exception {
		// JUnitDoclet begin method testcase.tearDown
		bordertool = null;
		super.tearDown();
		// JUnitDoclet end method testcase.tearDown
	}

	// JUnitDoclet begin javadoc_method mouseDown()
	/**
	 * Method testMouseDown is testing mouseDown
	 * @see org.jhotdraw.figures.BorderTool#mouseDown(java.awt.event.MouseEvent, int, int)
	 */
	// JUnitDoclet end javadoc_method mouseDown()
	public void testMouseDown() throws Exception {
		// JUnitDoclet begin method mouseDown
		// JUnitDoclet end method mouseDown
	}

	// JUnitDoclet begin javadoc_method action()
	/**
	 * Method testAction is testing action
	 * @see org.jhotdraw.figures.BorderTool#action(org.jhotdraw.framework.Figure)
	 */
	// JUnitDoclet end javadoc_method action()
	public void testAction() throws Exception {
		// JUnitDoclet begin method action
		// JUnitDoclet end method action
	}

	// JUnitDoclet begin javadoc_method reverseAction()
	/**
	 * Method testReverseAction is testing reverseAction
	 * @see org.jhotdraw.figures.BorderTool#reverseAction(org.jhotdraw.framework.Figure)
	 */
	// JUnitDoclet end javadoc_method reverseAction()
	public void testReverseAction() throws Exception {
		// JUnitDoclet begin method reverseAction
		// JUnitDoclet end method reverseAction
	}

	// JUnitDoclet begin javadoc_method testVault
	/**
	 * JUnitDoclet moves marker to this method, if there is not match
	 * for them in the regenerated code and if the marker is not empty.
	 * This way, no test gets lost when regenerating after renaming.
	 * <b>Method testVault is supposed to be empty.</b>
	 */
	// JUnitDoclet end javadoc_method testVault
	public void testVault() throws Exception {
		// JUnitDoclet begin method testcase.testVault
		// JUnitDoclet end method testcase.testVault
	}

}
