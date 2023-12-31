/*
 * @(#)JarEntry.java	1.21 03/12/19
 *
 * Copyright 2004 Sun Microsystems, Inc. All rights reserved.
 * SUN PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */

package padl.micropatterns.examples;

import java.io.IOException;
import java.security.cert.Certificate;
import java.util.jar.Attributes;
import java.util.zip.ZipEntry;

/**
 * This class is used to represent a JAR file entry.
 */
public
class JarEntry extends ZipEntry {
    Attributes attr;
    Certificate[] certs;
    //CodeSigner[] signers;

    /**
     * Creates a new <code>JarEntry</code> for the specified JAR file
     * entry name.
     *
     * @param name the JAR file entry name
     * @exception NullPointerException if the entry name is <code>null</code>
     * @exception IllegalArgumentException if the entry name is longer than
     *            0xFFFF bytes.
     */
    public JarEntry(String name) {
	super(name);
    }

    /**
     * Creates a new <code>JarEntry</code> with fields taken from the
     * specified <code>ZipEntry</code> object.
     * @param ze the <code>ZipEntry</code> object to create the 
     *           <code>JarEntry</code> from
     */
    public JarEntry(ZipEntry ze) {
	super(ze);
    }

    /**
     * Creates a new <code>JarEntry</code> with fields taken from the
     * specified <code>JarEntry</code> object.
     *
     * @param je the <code>JarEntry</code> to copy
     */
    public JarEntry(JarEntry je) {
	this((ZipEntry)je);
	this.attr = je.attr;
	this.certs = je.certs;
	//this.signers = je.signers;
    }

    /**
     * Returns the <code>Manifest</code> <code>Attributes</code> for this
     * entry, or <code>null</code> if none.
     *
     * @return the <code>Manifest</code> <code>Attributes</code> for this
     * entry, or <code>null</code> if none
     */
    public Attributes getAttributes() throws IOException {
	return this.attr;
    }

    /**
     * Returns the <code>Certificate</code> objects for this entry, or
     * <code>null</code> if none. This method can only be called once
     * the <code>JarEntry</code> has been completely verified by reading
     * from the entry input stream until the end of the stream has been
     * reached. Otherwise, this method will return <code>null</code>.
     *
     * <p>The returned certificate array comprises all the signer certificates
     * that were used to verify this entry. Each signer certificate is
     * followed by its supporting certificate chain (which may be empty).
     * Each signer certificate and its supporting certificate chain are ordered
     * bottom-to-top (i.e., with the signer certificate first and the (root)
     * certificate authority last).
     *
     * @return the <code>Certificate</code> objects for this entry, or
     * <code>null</code> if none.
     */
    public Certificate[] getCertificates() {
	return this.certs;
    }

    /**
     * Returns the <code>CodeSigner</code> objects for this entry, or
     * <code>null</code> if none. This method can only be called once
     * the <code>JarEntry</code> has been completely verified by reading
     * from the entry input stream until the end of the stream has been
     * reached. Otherwise, this method will return <code>null</code>.
     *
     * <p>The returned array comprises all the code signers that have signed
     * this entry. 
     *
     * @return the <code>CodeSigner</code> objects for this entry, or
     * <code>null</code> if none.
     *
     * @since 1.5
     */
    //public CodeSigner[] getCodeSigners() {
	//return signers;
    //}
}
