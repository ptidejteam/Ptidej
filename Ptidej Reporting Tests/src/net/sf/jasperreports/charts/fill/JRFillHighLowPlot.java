/*
 * ============================================================================
 * GNU Lesser General Public License
 * ============================================================================
 *
 * JasperReports - Free Java report-generating library.
 * Copyright (C) 2001-2006 JasperSoft Corporation http://www.jaspersoft.com
 * 
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307, USA.
 * 
 * JasperSoft Corporation
 * 303 Second Street, Suite 450 North
 * San Francisco, CA 94107
 * http://www.jaspersoft.com
 */
package net.sf.jasperreports.charts.fill;

import java.awt.Color;

import net.sf.jasperreports.charts.JRHighLowPlot;
import net.sf.jasperreports.engine.JRExpression;
import net.sf.jasperreports.engine.JRFont;
import net.sf.jasperreports.engine.base.JRBaseFont;
import net.sf.jasperreports.engine.fill.JRFillChartPlot;
import net.sf.jasperreports.engine.fill.JRFillObjectFactory;
import net.sf.jasperreports.engine.util.JRStyleResolver;


/**
 * @author Ionut Nedelcu (ionutned@users.sourceforge.net)
 * @version $Id: JRFillHighLowPlot.java,v 1.1 2008/09/29 16:21:42 guehene Exp $
 */
public class JRFillHighLowPlot extends JRFillChartPlot implements JRHighLowPlot
{

	/**
	 *
	 */
	protected JRFont timeAxisLabelFont = null;
	protected Color timeAxisLabelColor = null;
	protected JRFont timeAxisTickLabelFont = null;
	protected Color timeAxisTickLabelColor = null;
	protected Color timeAxisLineColor = null;

	protected JRFont valueAxisLabelFont = null;
	protected Color valueAxisLabelColor = null;
	protected JRFont valueAxisTickLabelFont = null;
	protected Color valueAxisTickLabelColor = null;
	protected Color valueAxisLineColor = null;

	
	/**
	 *
	 */
	public JRFillHighLowPlot(
		JRHighLowPlot highLowPlot,
		JRFillObjectFactory factory
		)
	{
		super(highLowPlot, factory);

		this.timeAxisLabelFont = new JRBaseFont(null, null, highLowPlot.getChart(), highLowPlot.getTimeAxisLabelFont());
		this.timeAxisLabelColor = highLowPlot.getOwnTimeAxisLabelColor();
		this.timeAxisTickLabelFont = new JRBaseFont(null, null, highLowPlot.getChart(), highLowPlot.getTimeAxisTickLabelFont());
		this.timeAxisTickLabelColor = highLowPlot.getOwnTimeAxisTickLabelColor();
		this.timeAxisLineColor = highLowPlot.getTimeAxisLineColor();
		
		this.valueAxisLabelFont = new JRBaseFont(null, null, highLowPlot.getChart(), highLowPlot.getValueAxisLabelFont());
		this.valueAxisLabelColor = highLowPlot.getOwnValueAxisLabelColor();
		this.valueAxisTickLabelFont = new JRBaseFont(null, null, highLowPlot.getChart(), highLowPlot.getValueAxisTickLabelFont());
		this.valueAxisTickLabelColor = highLowPlot.getOwnValueAxisTickLabelColor();
		this.valueAxisLineColor = highLowPlot.getValueAxisTickLabelColor();
	}

	/**
	 *
	 */
	public JRExpression getTimeAxisLabelExpression()
	{
		return ((JRHighLowPlot)this.parent).getTimeAxisLabelExpression();
	}

	/**
	 *
	 */
	public JRFont getTimeAxisLabelFont()
	{
		return this.timeAxisLabelFont;
	}

	/**
	 *
	 */
	public void setTimeAxisLabelFont(JRFont font)
	{
	}
	
	/**
	 *
	 */
	public Color getTimeAxisLabelColor()
	{
		return JRStyleResolver.getTimeAxisLabelColor(this, this);
	}

	/**
	 *
	 */
	public Color getOwnTimeAxisLabelColor()
	{
		return this.timeAxisLabelColor;
	}

	/**
	 *
	 */
	public void setTimeAxisLabelColor(Color color)
	{
	}

	/**
	 *
	 */
	public JRFont getTimeAxisTickLabelFont()
	{
		return this.timeAxisTickLabelFont;
	}

	/**
	 *
	 */
	public void setTimeAxisTickLabelFont(JRFont font)
	{
	}
	
	/**
	 *
	 */
	public Color getTimeAxisTickLabelColor()
	{
		return JRStyleResolver.getTimeAxisTickLabelColor(this, this);
	}

	/**
	 *
	 */
	public Color getOwnTimeAxisTickLabelColor()
	{
		return this.timeAxisTickLabelColor;
	}

	/**
	 *
	 */
	public void setTimeAxisTickLabelColor(Color color)
	{
	}

	/**
	 *
	 */
	public String getTimeAxisTickLabelMask()
	{
		return ((JRHighLowPlot)this.parent).getTimeAxisTickLabelMask();
	}

	/**
	 *
	 */
	public void setTimeAxisTickLabelMask(String mask)
	{
	}

	/**
	 *
	 */
	public Color getTimeAxisLineColor()
	{
		return JRStyleResolver.getTimeAxisLineColor(this, this);
	}

	/**
	 *
	 */
	public Color getOwnTimeAxisLineColor()
	{
		return this.timeAxisLineColor;
	}

	/**
	 *
	 */
	public void setTimeAxisLineColor(Color color)
	{
	}

	/**
	 *
	 */
	public JRExpression getValueAxisLabelExpression()
	{
		return ((JRHighLowPlot)this.parent).getValueAxisLabelExpression();
	}

	/**
	 *
	 */
	public JRFont getValueAxisLabelFont()
	{
		return this.valueAxisLabelFont;
	}

	/**
	 *
	 */
	public void setValueAxisLabelFont(JRFont font)
	{
	}
	
	/**
	 *
	 */
	public Color getValueAxisLabelColor()
	{
		return JRStyleResolver.getValueAxisLabelColor(this, this);
	}

	/**
	 *
	 */
	public Color getOwnValueAxisLabelColor()
	{
		return this.valueAxisLabelColor;
	}

	/**
	 *
	 */
	public void setValueAxisLabelColor(Color color)
	{
	}

	/**
	 *
	 */
	public JRFont getValueAxisTickLabelFont()
	{
		return this.valueAxisTickLabelFont;
	}

	/**
	 *
	 */
	public void setValueAxisTickLabelFont(JRFont font)
	{
	}
	
	/**
	 *
	 */
	public Color getValueAxisTickLabelColor()
	{
		return JRStyleResolver.getValueAxisTickLabelColor(this, this);
	}

	/**
	 *
	 */
	public Color getOwnValueAxisTickLabelColor()
	{
		return this.valueAxisTickLabelColor;
	}

	/**
	 *
	 */
	public void setValueAxisTickLabelColor(Color color)
	{
	}

	/**
	 *
	 */
	public String getValueAxisTickLabelMask()
	{
		return ((JRHighLowPlot)this.parent).getValueAxisTickLabelMask();
	}

	/**
	 *
	 */
	public void setValueAxisTickLabelMask(String mask)
	{
	}

	/**
	 *
	 */
	public Color getValueAxisLineColor()
	{
		return JRStyleResolver.getValueAxisLineColor(this, this);
	}

	/**
	 *
	 */
	public Color getOwnValueAxisLineColor()
	{
		return this.valueAxisLineColor;
	}

	/**
	 *
	 */
	public void setValueAxisLineColor(Color color)
	{
	}
	
	public boolean isShowOpenTicks()
	{
		return ((JRHighLowPlot)this.parent).isShowOpenTicks();
	}


	public boolean isShowCloseTicks()
	{
		return ((JRHighLowPlot)this.parent).isShowCloseTicks();
	}
}
