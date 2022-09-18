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
package org.jhotdraw.test.samples.javadraw;

import java.awt.Image;

// JUnitDoclet begin import
import org.jhotdraw.application.DrawApplication;
import org.jhotdraw.samples.javadraw.PatternPainter;
import org.jhotdraw.test.JHDTestCase;
import org.jhotdraw.util.Iconkit;
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
 * TestCase PatternPainterTest is generated by
 * JUnitDoclet to hold the tests for PatternPainter.
 * @see org.jhotdraw.samples.javadraw.PatternPainter
 */
// JUnitDoclet end javadoc_class
public class PatternPainterTest
// JUnitDoclet begin extends_implements
extends JHDTestCase
// JUnitDoclet end extends_implements
{
	// JUnitDoclet begin class
	// instance variables, helper methods, ... put them in this marker
	private PatternPainter patternpainter;
	// JUnitDoclet end class

	/**
	 * Constructor PatternPainterTest is
	 * basically calling the inherited constructor to
	 * initiate the TestCase for use by the Framework.
	 */
	public PatternPainterTest(String name) {
		// JUnitDoclet begin method PatternPainterTest
		super(name);
		// JUnitDoclet end method PatternPainterTest
	}

	/**
	 * Factory method for instances of the class to be tested.
	 */
	public PatternPainter createInstance() throws Exception {
		// JUnitDoclet begin method testcase.createInstance
		Image img = Iconkit.instance().loadImage(DrawApplication.IMAGES + "SEL1.gif", true);
		return new PatternPainter(img);
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
		patternpainter = createInstance();
		// JUnitDoclet end method testcase.setUp
	}

	/**
	 * Method tearDown is overwriting the framework method to
	 * clean up after each single test of this TestCase.
	 * It's called from the JUnit framework only.
	 */
	protected void tearDown() throws Exception {
		// JUnitDoclet begin method testcase.tearDown
		patternpainter = null;
		super.tearDown();
		// JUnitDoclet end method testcase.tearDown
	}

	// JUnitDoclet begin javadoc_method draw()
	/**
	 * Method testDraw is testing draw
	 * @see org.jhotdraw.samples.javadraw.PatternPainter#draw(java.awt.Graphics, org.jhotdraw.framework.DrawingView)
	 */
	// JUnitDoclet end javadoc_method draw()
	public void testDraw() throws Exception {
		// JUnitDoclet begin method draw
		// JUnitDoclet end method draw
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
