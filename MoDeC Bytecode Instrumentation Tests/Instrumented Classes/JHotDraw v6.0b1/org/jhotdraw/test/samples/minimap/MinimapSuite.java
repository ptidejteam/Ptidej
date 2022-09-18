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
package org.jhotdraw.test.samples.minimap;

import junit.framework.TestSuite;
// JUnitDoclet begin import
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
* TestSuite MinimapSuite
*/
// JUnitDoclet end javadoc_class
public class MinimapSuite
// JUnitDoclet begin extends_implements
// JUnitDoclet end extends_implements
{
	// JUnitDoclet begin class
	// JUnitDoclet end class

	public static TestSuite suite() {

		TestSuite suite;

		suite = new TestSuite("org.jhotdraw.test.samples.minimap");

		suite.addTestSuite(org.jhotdraw.test.samples.minimap.MiniMapDesktopTest.class);
		suite.addTestSuite(org.jhotdraw.test.samples.minimap.MiniMapApplicationTest.class);

		// JUnitDoclet begin method suite()
		// JUnitDoclet end method suite()

		return suite;
	}

	/**
	* Method to execute the TestSuite from command line
	* using JUnit's textui.TestRunner .
	*/
	public static void main(String[] args) {
		// JUnitDoclet begin method testsuite.main
		junit.textui.TestRunner.run(suite());
		// JUnitDoclet end method testsuite.main
	}
}
