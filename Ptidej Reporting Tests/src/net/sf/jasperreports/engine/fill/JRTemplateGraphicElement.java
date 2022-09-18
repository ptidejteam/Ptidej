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
package net.sf.jasperreports.engine.fill;

import java.awt.Color;
import java.io.IOException;
import java.io.ObjectInputStream;

import net.sf.jasperreports.engine.JRCommonGraphicElement;
import net.sf.jasperreports.engine.JRConstants;
import net.sf.jasperreports.engine.JRDefaultStyleProvider;
import net.sf.jasperreports.engine.JRGraphicElement;
import net.sf.jasperreports.engine.JROrigin;
import net.sf.jasperreports.engine.JRPen;
import net.sf.jasperreports.engine.base.JRBasePen;
import net.sf.jasperreports.engine.util.JRPenUtil;
import net.sf.jasperreports.engine.util.JRStyleResolver;


/**
 * @author Teodor Danciu (teodord@users.sourceforge.net)
 * @version $Id: JRTemplateGraphicElement.java,v 1.1 2008/09/29 16:20:01 guehene Exp $
 */
public abstract class JRTemplateGraphicElement extends JRTemplateElement implements JRCommonGraphicElement
{


	/**
	 *
	 */
	private static final long serialVersionUID = JRConstants.SERIAL_VERSION_UID;

	/**
	 *
	 */
	protected JRPen linePen = null;
	private Byte fill = null;


	/**
	 *
	 */
	protected JRTemplateGraphicElement(JROrigin origin, JRDefaultStyleProvider defaultStyleProvider)
	{
		super(origin, defaultStyleProvider);
	}

	/**
	 *
	 */
	protected JRTemplateGraphicElement(JROrigin origin, JRDefaultStyleProvider defaultStyleProvider, JRGraphicElement graphicElement)
	{
		super(origin, defaultStyleProvider);

		setGraphicElement(graphicElement);
	}


	/**
	 *
	 */
	protected void setGraphicElement(JRGraphicElement graphicElement)
	{
		super.setElement(graphicElement);
		
		this.linePen = graphicElement.getLinePen().clone(this);
		
		setFill(graphicElement.getOwnFill());
	}

	/**
	 *
	 */
	public JRPen getLinePen()
	{
		return this.linePen;
	}
		
	/**
	 * @deprecated Replaced by {@link #getLinePen()}
	 */
	public byte getPen()
	{
		return JRPenUtil.getPenFromLinePen(this.linePen);
	}
		
	/**
	 * @deprecated Replaced by {@link #getLinePen()}
	 */
	public Byte getOwnPen()
	{
		return JRPenUtil.getOwnPenFromLinePen(this.linePen);
	}

	/**
	 * @deprecated Replaced by {@link #getLinePen()}
	 */
	public void setPen(byte pen)
	{
		setPen(new Byte(pen));
	}
		
	/**
	 * @deprecated Replaced by {@link #getLinePen()}
	 */
	public void setPen(Byte pen)
	{
		JRPenUtil.setLinePenFromPen(pen, this.linePen);
	}
		
	/**
	 *
	 */
	public byte getFill()
	{
		return JRStyleResolver.getFill(this);
	}
		
	/**
	 *
	 */
	public Byte getOwnFill()
	{
		return this.fill;
	}
		
	/**
	 *
	 */
	protected void setFill(byte fill)
	{
		this.fill = new Byte(fill);
	}
	
	/**
	 *
	 */
	protected void setFill(Byte fill)
	{
		this.fill = fill;
	}
	

	/**
	 * 
	 */
	public Float getDefaultLineWidth() 
	{
		return JRPen.LINE_WIDTH_1;
	}

	/**
	 * 
	 */
	public Color getDefaultLineColor() 
	{
		return getForecolor();
	}

		
	/**
	 * This field is only for serialization backward compatibility.
	 */
	private Byte pen;
	
	private void readObject(ObjectInputStream in) throws IOException, ClassNotFoundException
	{
		in.defaultReadObject();
		
		if (this.linePen == null)
		{
			this.linePen = new JRBasePen(this);
			JRPenUtil.setLinePenFromPen(this.pen, this.linePen);
			this.pen = null;
		}
	}
}
